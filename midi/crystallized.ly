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
	title = "Crystallized"
	composer = "Haken"
	arranger = "arr. Trey Boehm"
}


VoiceOne = \relative c''' {
    \set Staff.instrumentName = #"Vocals"
    \set Staff.midiInstrument = #"voice oohs"
	\override Score.BarNumber #'break-visibility = #'#(#f #f #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2
	\tempo 4 = 200
	\time 7/4
    \key d \major

    g8 r e r fis d r e r g a4 fis |
    g8 r e r fis d r e r g a4 b |
    g8 r e r fis d r e r g a4 fis |
    g8 r e r fis4 d8 e4 g a r8 |

    g8 r e r fis d r e r g a4 fis |
    g8 r e r fis d r e r g a4 b |
    g8 r e r fis d r e r g a4 fis |
    g8 r e r fis d r e r g a4 b |

    g8 r e r fis d r e r g a4 fis |
    g8 r e r fis d r e r g a4 b |
    g8 r e r fis d r e r g a4 fis |
    g8 r e r fis d r e r g a4 b |

    g8 r e r fis d r e r g a4 fis |
    g8 r e r fis d r e r g a4 b |
    g8 r e r fis d r e r g a4 fis |
    g8 r e r fis4 d8 e4 g a r8 |
}

VoiceTwo = \relative c'' {
    \set Staff.instrumentName = #"Vocals"
    \set Staff.midiInstrument = #"voice oohs"
	\override Score.BarNumber #'break-visibility = #'#(#f #f #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2
	\tempo 4 = 200
	\time 7/4
    \key d \major

    b8 r g r a r fis g r b r cis r a |
    b8 r g r a r fis g r b r cis r d |
    b8 r g r a r fis g r b r cis r a |
    b8 r g r a r fis g r b r cis4 r8 |

    b8 r g r a r fis g r b r cis r a |
    b8 r g r a r fis g r b r cis r d |
    b8 r g r a r fis g r b r cis r a |
    b8 r g r a r fis g r b r cis r d |

    b8 r g r a r fis g r b r cis r a |
    b8 r g r a r fis g r b r cis r d |
    b8 r g r a r fis g r b r cis r a |
    b8 r g r a r fis g r b r cis r d |

    b8 r g r a r fis g r b r cis r a |
    b8 r g r a r fis g r b r cis r d |
    b8 r g r a r fis g r b r cis r a |
    b8 r g r a r fis g r b r cis4 r8 |
}

VoiceThree = \relative c' {
    \set Staff.instrumentName = #"Vocals"
    \set Staff.midiInstrument = #"voice oohs"
	\override Score.BarNumber #'break-visibility = #'#(#f #f #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2
	\tempo 4 = 200
	\time 7/4
    \key d \major

    R1..*4 |

    e2 d4. e4 d b d8 |
    e2 fis4 g8 a r4 r2 |
    e2 d4. e4 d b d8 |
    e2 fis4 d8 e r4 r2 |

    e2 d4. e4 d b d8 |
    e2 fis4 g8 a r4 r8 b, d g |
    e2 d4. e4 d b d8 |
    e2 fis4 d8 e r4 r2 |

    e2 d4. e4 d b d8 |
    e2 fis4 g8 a r4 r8 d, f g |
    e2 d4. e4 d b d8 |
    e2 fis4 d8 e r4 r8 b d g |
}

VoiceFour = \relative c'' {
    \set Staff.instrumentName = #"Vocals"
    \set Staff.midiInstrument = #"voice oohs"
	\override Score.BarNumber #'break-visibility = #'#(#f #f #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2
	\tempo 4 = 200
	\time 7/4
    \key d \major

    R1..*4 |

    R1..*2 |
    r4 b2. fis8 a4 g fis8 |
    g2 fis4 d8 d r4 r2 |
    
    r4 b'2~ b8 a g4 fis8 g4 fis8 |
    e4. fis4 g a8 r2. |
    R1..*2 |

    r4 b2. a8 g fis g4 fis8 |
    e4. fis4 g a8 r2. |
    r4 b4. a4 g b g fis8 |
    g8 fis e4 fis d8 d r2. |
}

Glock = \relative c''' {
    \set Staff.instrumentName = #"Glockenspiel"
    \set Staff.midiInstrument = #"glockenspiel"
    \override Score.BarNumber #'break-visibility = #'#(#f #f #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2
	\tempo 4 = 200
	\time 7/4
    \key d \major

    R1..*4 |

    R1..*4 |

    g8 e, e' e, fis' e, d' e e, g' e, a' e, fis' |
    g8 e, e' e, fis' e, d' e e, g' e, a' e, b' |
}

% Generate a PDF of the entire score
\book {
	\score {
		<<
			\new Staff { \VoiceOne }
            \new Staff { \VoiceTwo }
            \new Staff { \VoiceThree }
            \new Staff { \VoiceFour }
            %\new Staff { \Glock }
		>>
	}
	
}

% Generate a MIDI of all parts together
\book {
	\bookOutputSuffix "midi"
	\score {
		<<
            \new Staff { \VoiceOne }
            \new Staff { \VoiceTwo }
            \new Staff { \VoiceThree }
            \new Staff { \VoiceFour }
            %\new Staff { \Glock }
		>>
		\midi { }
	}
}

\version "2.18.2"

