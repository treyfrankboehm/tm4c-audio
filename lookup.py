import os

os.system("rm lookup.h")

f = open("lookup.h", 'w')
top = "\
/* lookup.h\n\
 * Lookup table to multiply unsigned 6-bit integers quickly.\n\
 * Trey Boehm, 2017-04-22\n\
 * Hardware connections: None\n\
 */\n\

#include <stdint.h>\n\

static const uint16_t MultLookup[64][64] = {\n\
"
f.write(top)
for x in range(64):
    row = "    {"
    for y in range(64):
        product = x*y
        # No comma after the last entry in an array
        if y == 63:
            row += ("%d" % product)
        else:
            row += ("%d, " % product)
    # No comma after the last array
    if x == 63:
        row += "}\n"
    else:
        row += "},\n"
    f.write(row)
f.write("};\n")
f.close()
exit(0)
