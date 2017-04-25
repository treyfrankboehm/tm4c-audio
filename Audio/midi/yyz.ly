\paper {
	myStaffSize = #20
	#(define fonts
		(make-pango-font-tree
			"Times New Roman"
			"Nimbus Sans"
			"Luxi Mono"
			(/ myStaffSize 20)))
	#(define bottom-margin (* 2 cm))
	#(define top-margin (* 1 cm))
}

\header {
	title = "YYZ"
}

Guitar = \relative c'' {
	\override Score.BarNumber #'break-visibility = #'#(#f #t #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2
    \set Staff.instrumentName = #"Guitar"
    \set Staff.midiInstrument = #"overdriven guitar"

	\tempo 4 = 208
	\time 5/4
	\key e \minor

    c,4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |

    c'4 r8 c4 c c r8 |
    c4 c c c8 r r4 |

    \time 4/4
    \tempo 4 = 144
    r1 |
    c16 c cis dis e fis gis a b cis dis e \times 2/3 {dis8 cis c~} |
    c4. r4. \times 2/3 {c8 b g} |
    fis8 r r4 d'16 d c d c b a g |
    fis2. fis,4 |

    \time 4/4
    \tempo 4 = 140
    \key b \minor

	a'16 a fis a fis f e8 cis2 |
	a'16 a fis a fis e cis8 b8. cis fis,8 |
	a'16 a fis a fis f e8 cis2 |
	a'16 a fis a fis e cis8 b8. cis fis,8 |

	c''16 c a c a aes g8 e2 |
	c'16 c a c a g e8 d8. e a,8 |
	c'16 c a c a aes g8 e2 |
    c'16 c a c a gis g e g g e g8~ g16 e8 |
    
    a16 a fis a fis f e8 cis2 |
	a'16 a fis a fis e cis8 b8. cis fis,8 |
	a'16 a fis a fis f e8 cis2 |
	a'16 a fis a fis e cis8 b8. cis fis,8 |

    c''16 c a c a aes g8 e2 |
	c'16 c a c a g e8 d8. e a,8 |
	c'16 c a c a aes g8 e2 |
	c'16 c a c a g e8 d8. e a,8 |

    dis8. e fis8 a,2 |
    r8 dis e fis gis4 fis |
    dis8. e fis8 a,16 a a a b4 |
    r8 dis e fis gis4 fis |

    c8. d e8 d16 e d e g4 |
    r8 c, d e d16 e d e g e g8 |
    c,8. d e8 d16 e d e g4 |
    r8 c, d e d16 e d e g e g8 |

    dis8. e fis8 a,2 |
    r8 dis e fis gis4 fis |
    dis8. e fis8 a,16 a a a b4 |
    r8 dis e fis gis4 fis |

    c8. d e8 d16 e d e g4 |
    r8 c, d e d16 e d e g e g8 |
    c,8. d e8 d16 e d e g4 |
    r8 c, d e d16 e d e g e g8 |

    b8 r r4 r2 |

}

Keyboards = \relative c'' {
    \set Staff.instrumentName = #"Keyboards"
    \set Staff.midiInstrument = #"string ensemble 1"
	\override Score.BarNumber #'break-visibility = #'#(#f #f #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2

    \key e \minor
    \time 5/4

    fis1~ fis4~ |
    fis1~ fis4 |
    gis1~ gis4~ |
    gis1~ gis4 |
    dis2.~ dis8 cis8~ cis4~ |
    cis1~ cis4 |
    c1~ c4~ |
    c1~ c4 |
    fis1~ fis4~ |
    fis1~ fis4 |
    gis1~ gis4~ |
    gis1~ gis4 |
    dis2.~ dis8 cis8~ cis4~ |
    cis1~ cis4 |
    c1~ c4~ |
    c1~ c4 |
    c1~ c4~ |
    c1~ c4 |

    r1 r4 |
    r1 r4 |

}

Bass = \relative c {
    \set Staff.instrumentName = #"Bass"
    \set Staff.midiInstrument = #"electric bass (finger)"
	\override Score.BarNumber #'break-visibility = #'#(#f #f #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2

    \clef bass

    \key e \minor
    \time 5/4

    c4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c'4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |
    c4 fis,8 c'4 c c fis,8 |
    c'4 c c c fis,8 fis |

    c'4 r8 c4 c c r8 |
    c4 c c c8 r r4 |

    \time 4/4
    r1 |
    c16 c cis dis e fis gis a b cis dis e \times 2/3 {dis8 cis c~} |
    c4. r4. \times 2/3 {c8 b g} |
    fis8 r r4 d'16 d c d c b a g |
    fis2. fis,4 |

    \time 4/4
    \key b \minor

    a'16 a fis a fis f e8 cis2 |
    a'16 a fis a fis f e cis b8. cis a8 |
    a'16 a fis a fis f e8 cis2 |
    a'16 a fis a fis f e cis b8. cis a8 |

    c'16 c a c a gis g8 e2 |
    c'16 c a c a gis g e d8. e a,8 |
    c'16 c a c a gis g8 e2 |
    c'16 c a c a gis g e g g e g r g e8 |

    a16 a fis a fis f e8 cis2 |
    a'16 a fis a fis f e cis b8. cis a8 |
    a'16 a fis a fis f e8 cis2 |
    a'16 a fis a fis f e cis b8. cis a8 |

    c'16 c a c a gis g8 e2 |
    c'16 c a c a gis g e d8. e a,8 |
    c'16 c a c a gis g8 e2 |
    c'16 c a c a gis g e d8. e a,8 |

    b8. dis fis,8 e'2 |
    r8 b8 dis fis, a'16 a fis a8 a16 e8 |
    b8. dis fis,8 e'4 fis |
    r8 b,8 dis fis, a'16 a fis a8 a16 e8 |

    c8. g' d'8 c4 d |
    r8 c, g' d' c16 c a c8 c16 g8 |
    c,8. g' d'8 c e d c |
    b16 c g c a gis g e a fis e g r g e8 |

    b8. dis fis,8 e'2 |
    r8 b8 dis fis, a'16 a fis a8 a16 e8 |
    b8. dis fis,8 e'4 fis |
    r8 b, dis fis, a'16 a fis a8 a16 e8 |

    c8. g' a8 d4 c |
    r8 c, g' d' c16 c a c8 c16 g8 |
    c,8. g' d'8 c4 d |
    c8 b c b a g f d |

    b8 r r4 r2
}

Drums = \drummode {
    \set Staff.instrumentName = #"Drums"
	\override Score.BarNumber #'break-visibility = #'#(#f #f #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2

    \time 5/4

    cymc4 bd8 sn4 sn sn bd8 |
    sn4 sn sn sn bd8 bd |
    cymc4 bd8 sn4 sn sn bd8 |
    sn4 sn sn sn bd8 bd |
    cymc4 bd8 sn4 sn sn bd8 |
    sn4 sn sn sn bd8 bd |
    cymc4 bd8 sn4 sn sn bd8 |
    sn4 sn sn sn sn16 sn sn sn |
    cymc4 bd8 sn4 sn sn bd8 |
    sn4 sn sn sn bd8 bd |
    sn4 sn8 bd cymr bd cymr bd cymr bd |
    sn8 bd sn bd sn bd sn4 sn16 sn sn sn |
    cymc4 bd8 sn4 sn sn bd8 |
    sn4 sn sn sn bd8 bd |
    sn4 sn8 bd cymr bd cymr bd cymr bd |
    sn8 bd sn bd sn bd sn4 toml16 toml toml toml |
    cymc4 bd8 sn4 sn sn bd8 |
    sn4 sn sn sn bd8 bd |

    cymr8 r r cymr r cymr r cymr r4 |
    cymr8 r cymr r cymr r cymr r r4 |

    \time 4/4
    r1 |

    sn16 sn sn sn sn sn sn sn sn sn sn sn \times 2/3 {sn8 sn sn} |
    r2. \times 2/3 {sn8 sn sn} |
    cymr8 r r4 sn16-> sn sn sn sn-> sn sn sn |
    cyms2. r4 |

    \time 4/4

    cymc4 sn4 hhc8 bd sn4 |
    hhc8 bd16 bd sn8 bd hhc8 bd sn4 |
    hhc8 bd sn4 hhc8 bd16 bd sn4 |
    hhc8 bd sn4 hhc8 bd sn4 |

    cymc4 sn hhc8 bd sn4 |
    hhc8 bd16 bd sn4 hhc8 bd sn4 |
    hhc8. bd16 sn4 hhc8 bd sn4 |
    hhc8 bd16 bd sn4 hhc8 bd sn4 |

    sn16 sn r sn r sn sn sn cymc4 sn |
    hhc8 bd sn4 hhc8 bd16 bd sn4 |
    hhc8 bd sn4 hhc8 bd16 bd sn4 |
    hhc8 bd sn4 hhc8 bd16 bd sn8 hhc |

    cymc8 bd16 bd sn4 hhc8 bd16 bd sn4 |
    hhc8 bd sn4 hhc8 bd16 bd sn4 |
    hhc8 bd sn4 hhc8 bd16 bd sn4 |
    hhc8 bd16 bd sn8 sn tomh16 tomh tomh tommh tomml tomml toml toml |

    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn16 cymr16 bd8 |
    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn16 cymr16 bd8 |
    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn16 cymr16 bd8 |
    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn4 |

    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn16 cymr16 bd8 |
    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn16 cymr16 bd8 |
    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn16 cymr16 bd8 |
    bd8 cymr16 cymr sn8 bd sn16 sn sn hhc-> r hhc-> sn sn |

    cymc4 sn8 bd cymr bd16 bd sn cymr bd8 |
    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn16 cymr16 bd8 |
    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn16 cymr16 bd8 |
    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn16 cymr cymr8 |

    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn16 cymr16 bd8 |
    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn16 cymr16 bd8 |
    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn16 cymr16 bd8 |
    bd8 cymr16 cymr sn8 bd cymr bd16 bd sn-> bd sn-> bd |

    hhp8 r r4 r2 |

}


% Generate a PDF of the entire score
\book {
	\score {
		<<
            \new Staff { \Guitar }
            \new Staff { \Keyboards }
            \new Staff { \Bass}
			\new DrumStaff { \Drums }
		>>
	}
	
}

% Generate a MIDI of all parts together
\book {
	\bookOutputSuffix "midi"
	\score {
        <<
            \new Staff { \Guitar }
            \new Staff { \Keyboards }
            \new Staff { \Bass}
		    \new DrumStaff { \Drums }
        >>
		\midi { }
	}
}

\version "2.18.2"

