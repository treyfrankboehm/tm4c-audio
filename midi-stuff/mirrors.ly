\paper {
	myStaffSize = #20
	#(define fonts
		(make-pango-font-tree
			"Times New Roman"
			"Helvetica"
			"Inconsolata"
			(/ myStaffSize 20)))
	#(define bottom-margin (* 2 cm))
	#(define top-margin (* 1 cm))
}

\header {
	title = "21st Century Schizoid Man"
	subtitle = "Mirrors"
	composer = "Composition: King Crimson"
	arranger = "Transcription: Trey Boehm"
}

Alto = \transpose ees c { \relative c'' {
    \set Staff.instrumentName = #"A. Sax"
    %\set Staff.midiInstrument = #"alto sax"
	\override Score.BarNumber #'break-visibility = #'#(#f #f #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2
	\tempo 4 = 144
	\time 6/8
	\key c \minor

	bes'16. f16 g16. r8 bes16. f16 g16. r8|
	bes16. f16 g8 f ees c r16.  |

	bes'16. f16 g16. r8 bes16. f16 g16. r8|
	bes16. f16 g8 f ees c r16.  |

	g'16. d16 f16. r8 g16. d16 f16. r8 |
	g16. d16 f8 f ees c r16. |

	bes'16. f16 g16. r8 bes16. f16 g16. r8|
	bes16. f16 g8 f ees c r16.  |

	bes'16. f16 g16. r8 bes16. f16 g16. r8|
	bes16. f16 g8 f ees c r16.  |

	bes'16. f16 g16. r8 bes16. f16 g16. r8|
    \time 5/8
	bes16. f16 g8 f ees c16. |

	\time 4/4
	g16 bes c cis d f d cis f g bes cis \times 2/3 {c bes g} bes c |
	d16 d f d cis g' r8 r2 |
	g,,16 bes c cis d f d cis f g bes cis \times 2/3 {c bes g} bes c |
	d16 d f d cis g' r cis, [c] r bes [g] r f [d] r |
	e f g bes c8 g16 d'8 g,16 c8 g16 bes8 g16 c8
	g16 d'8 g,16 f8 d cis c bes

	g16 bes c cis d f d cis f g bes cis \times 2/3 {c bes g} bes c |
	d16 d f d cis g' r8 r2 |
	cis,16 d f cis d f r8 r2 |
	cis16 d f d cis c r8 r2 |
	cis16 d f g r cis, [c] r bes [g] r f [d] r r8 |
    \time 7/8
	cis'16 d f g r cis, [c] r bes [g] r f [d] bes |

    \time 4/4
	g16 \p bes c d f8 d16 a'8 d,16 g8 d16 f8 d16 |
	g8 d16 a'8 d,16 f8 d cis c bes |
	g16 bes c d f8 d16 a'8 d,16 g8 d16 f8 d16 |
	g8 d16 a'8 d,16 f8 d cis c bes |
	c16 e f g bes8 g16 d'8 g,16 c8 g16 bes8 g16 |
	c8 g16 d'8 g,16 f8 d cis c bes |

	g16 bes c cis d f d cis f g bes cis \times 2/3 {c bes g} bes c |
	d16 d f d cis g' r8 r2 |
	cis,16 d f cis d f r8 r2 |
	cis16 d f d cis c r8 r2 |
	cis16 d f g r cis, [c] r bes [g] r f [d] r r8 |
	cis'16 d f g r cis, [c] r bes [g] r bes d f g \bendAfter -4 r |

    R1*3 |
	
	\time 6/8
	c,,16 [c r c r c] ees8 e f |
	c16 [c r c r c] b8 bes g |
	c16 [c r c r c] ees8 e f |
	fis,8 [g bes] g [bes b] |
	c16 [c r c r c] ees8 e f |
	c16 [c r c r c] b8 bes g |
	c16 [c r c r c] ees8 e f |
	fis8 [g bes] g [bes b] |
    c16 [c r c r c] ees8 e f |
	c16 [c r c r c] b8 bes g |
	c16 [c r c r c] ees8 e f |
    fis,16 g bes fis g bes fis g bes fis g bes |
    c16 [c r c r c] ees8 e f |
	c16 [c r c r c] b8 bes g |
	c16 [c r c r c] ees8 e f |

	fis,16 g bes fis g bes fis g bes fis g bes |
	fis16 g bes fis g bes fis g bes fis g bes |
	fis16 g bes fis g bes fis g bes fis g bes |
	fis16 g bes fis g bes g4~ g8 \bendAfter -8 |

}}

\book {
	\score {
		<<
            << \Alto >>
		>>
	}
}

\book {
    \bookOutputSuffix "midi"
	\score {
		<<
            << \transpose c ees, {\Alto} >>
		>>
		\midi { }
	}
}

\version "2.18.2"
