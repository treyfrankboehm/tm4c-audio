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
	title = "Paradigm Shift"
    subtitle = "Liquid Tension Experiment"
	composer = "Levin, Petrucci, Portnoy, Rudess"
    arranger = "Arranged for MIDI by Boehm"
}

Guitar = \relative c'' {
    \set Staff.instrumentName = #"Guitar"
    \set Staff.midiInstrument = #"overdriven guitar"
	\override Score.BarNumber #'break-visibility = #'#(#f #f #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2

	\tempo 4 = 200
	\time 3/4

    e'16 \ff f e d e d cis d e d cis d |
    e16  f e d e d cis d e d cis d | 
    e16  f e d e d cis d e d cis d | 
    g16 f d c ais g ais c cis c ais g |
    f16 d ais' g f d c ais d c ais g |

    r2 r8 g8 \f |
    \tempo 4 = 168
    \time 4/4
    ais16 g g ais g g ais g g ais g g ais g c g |
    ais16 g g ais g g ais g g ais g g f d f d |
    ais'16 g g ais g g ais g g ais g g ais g c g |
    cis g c g ais g g ais g g d d g d f d |

    ais'16 g g ais g g ais g g ais g g ais g c g |
    ais16 g g ais g g ais g g ais g g f d f d |
    ais'16 g g ais g g ais g g ais g g ais g c g |
    cis g c g ais g g ais g g d d g d f d |

}

Keyboards = \relative c'' {
    \set Staff.instrumentName = #"Keyboards"
    \set Staff.midiInstrument = #"bright acoustic"
	\override Score.BarNumber #'break-visibility = #'#(#f #f #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2

	\tempo 4 = 200
	\time 3/4

    e16 \mf f e d e d cis d e d cis d |
    e16  f e d e d cis d e d cis d | 
    e16  f e d e d cis d e d cis d | 
    g16 f d c ais g ais c cis c ais g |
    f16 d ais' g f d c ais d c ais g |

    \clef bass
    r2 r8 g8 \mp |
    \tempo 4 = 168
    \time 4/4

    ais16 g g ais g g ais g g ais g g ais g c g |
    ais16 g g ais g g ais g g ais g g f d f d |
    ais'16 g g ais g g ais g g ais g g ais g c g |
    cis g c g ais g g ais g g d d g d f d |

    ais'16 g g ais g g ais g g ais g g ais g c g |
    ais16 g g ais g g ais g g ais g g f d f d |
    ais'16 g g ais g g ais g g ais g g ais g c g |
    cis g c g ais g g ais g g d d g d f d |

}



Bass = \relative c {
    \set Staff.instrumentName = #"Bass"
    \set Staff.midiInstrument = #"electric bass (finger)"
	\override Score.BarNumber #'break-visibility = #'#(#f #f #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2

    \clef bass
	\tempo 4 = 200
	\time 3/4

    R2.*3 |
    g4. e |
    f4. d |

    r2. |
    \time 4/4
    \tempo 4 = 168

    g2. ais8 c |
    g2. f8 d |
    g2. ais8 c |
    cis8 c ais8 e16 f~ f c d8 g16 f d8 |

    g2. ais8 c |
    g2. f8 d |
    g2. ais8 c |
    cis8 c ais8 e16 f~ f c d8 g16 f d8 |
}

Drums = \drummode {
    \set Staff.instrumentName = #"Drums"
	\override Score.BarNumber #'break-visibility = #'#(#f #f #t)
	\compressFullBarRests
	\override MultiMeasureRest #'expand-limit = #2

	\tempo 4 = 200
	\time 3/4

    sn16 sn bd bd sn sn sn sn sn8 bd16 bd |
    sn8 bd16 bd sn sn sn sn sn8 bd16 bd |
    sn8 bd16 bd sn sn sn sn sn8 bd16 bd |
    sn8 bd16 bd sn8 bd tomh16 tomh tomh tomh |
    tommh tommh tommh tommh tomml tomml tomml tomml sn sn sn bd |

    r2. |
    \time 4/4
    \tempo 4 = 168

    hhp4 hhp hhp hhp |
    hhp4 hhp hhp hhp |
    hhp4 hhp hhp hhp |
    hhp4 hhp hhp hhp |

    hhp4 hhp hhp hhp |
    hhp4 hhp hhp hhp |
    hhp4 hhp hhp hhp |
    hhp4 hhp hhp hhp |


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
%}

\version "2.18.2"


