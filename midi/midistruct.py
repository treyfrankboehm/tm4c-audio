#!/usr/bin/env python3

import csv
import os
import sys
import re

try:
    filename = sys.argv[1][0:-5]
except IndexError:
    sys.stderr.write("Usage: ./midistruct.py [filename.midi]\n")
    exit(1)

# Define array to associate MIDI pitch numbers with my pitch macros in C
macroNums=["REST", "Cis0", "D0", "Dis0", "E0", "F0", "Fis0", "G0", "Gis0", "A0", "Ais0", "B0", "C1", "Cis1", "D1", "Dis1", "E1", "F1", "Fis1", "G1", "Gis1", "A1", "Ais1", "B1", "C2", "Cis2", "D2", "Dis2", "E2", "F2", "Fis2", "G2", "Gis2", "A2", "Ais2", "B2", "C3", "Cis3", "D3", "Dis3", "E3", "F3", "Fis3", "G3", "Gis3", "A3", "Ais3", "B3", "C4", "Cis4", "D4", "Dis4", "E4", "F4", "Fis4", "G4", "Gis4", "A4", "Ais4", "B4", "C5", "Cis5", "D5", "Dis5", "E5", "F5", "Fis5", "G5", "Gis5", "A5", "Ais5", "B5", "C6", "Cis6", "D6", "Dis6", "E6", "F6", "Fis6", "G6", "Gis6", "A6", "Ais6", "B6", "C7", "Cis7", "D7", "Dis7", "E7", "F7", "Fis7", "G7", "Gis7", "A7", "Ais7", "B7", "C8", "Cis8", "D8", "Dis8", "E8", "F8", "Fis8", "G8", "Gis8", "A8", "Ais8", "B8", "C9", "Cis9", "D9", "Dis9", "E9", "F9", "Fis9", "G9", "Gis9", "A9", "Ais9", "B9", "C10", "Cis10", "D10", "Dis10", "E10", "F10", "Fis10", "G10"]

os.system("midicsv %s.midi > %s.csv" % (filename, filename))

midiCSV = list(csv.reader(open("%s.csv" % filename)))

# Remove extra spaces after commas
for row in midiCSV:
    for item in range(len(row)):
        row[item] = re.sub(' ', '', row[item])

# Find the tempo
tempo = 0
for row in midiCSV:
    if "Tempo" in row:
        tempo = int(row[3])
        break

# Remove non-note events
i = 0
while 1:
    if i >= len(midiCSV):
        break
    elif not "Note_on_c" in midiCSV[i]:
        del midiCSV[i]
    else:
        i += 1

# [channel, time, note]
for i in range(len(midiCSV)):
    midiCSV[i] = [ int(midiCSV[i][0]),
                   int(midiCSV[i][1]),
                   int(midiCSV[i][4]) ]

# Give each event a length instead of start and stop. This means that
# rests will be their own event. I give them a pitch of 0. mStruct is 
# the data that will be formatted and written to a header file to be
# played with the DAC, formatted into 5 different structs (for the
# different channels). pitch is exactly as it is formatted in the
# Sound.c file (A4, Ais4, B5, etc) and duration is a period that can be
# supplied as-is. Tempo is taken into account here, too.
# TODO: - make sure 5 channels will work
#       - actually take tempo into account
mStruct = [ [], [], [], [], [] ]
for i in range(0,len(midiCSV)-1,2):
    channel   = midiCSV[i][0]
    pitch     = midiCSV[i][2]
    startTime = midiCSV[i][1]
    endTime   = midiCSV[i+1][1]
    duration  = endTime - startTime
    track     = midiCSV[i][0]
    mStruct[channel-2].append([macroNums[pitch], duration])

    # Check if a rest happens
    if i < len(midiCSV) - 2: # not yet at the last item
        nextTime = midiCSV[i+2][1]
        rest     = nextTime - endTime
        if rest:
            mStruct[channel-2].append([macroNums[0], rest])

head = "\
/* %.h: .midi -> .csv -> homemade C struct\n\
 * Copyright (c) 2017 Trey Boehm\n\
 * Include this file in Sound.c to make the note macros useful.\n\
 */\n\
\n\
struct song_struct {\n\
    uint32_t pitch;\n\
    uint32_t duration;\n\
};\n\
typedef struct song_struct song_t;\n\
"
f = open("%s.h" % filename, 'w')
f.write(head)
for i in range(len(mStruct)):
    eventCount = len(mStruct[i])
    if eventCount != 0:
        f.write("\nconst song_t channel%d = {\n" % i)
        for j in range(eventCount):
            f.write("\t{%s, %d},\n" %
                    (mStruct[i][j][0], mStruct[i][j][1]))
        f.write("\t{0, 0}\n};\n")
f.write("\n")
f.close()

# vim: set colorcolumn=72:
