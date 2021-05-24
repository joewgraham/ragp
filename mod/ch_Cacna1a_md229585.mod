TITLE P-type calcium channel

COMMENT

Constructed from the recording data provided by Bruce Bean.
Reference: Swensen AM and Bean BP (2005) Robustness of burst firing in dissociated purkinje neurons with acute or long-term reductions in sodium conductance. J Neurosci 25:3509-20

Current Model Reference: Anwar H, Hong S, De Schutter E (2010) Controlling Ca2+-activated K+ channels with models of Ca2+ buffering in Purkinje cell. Cerebellum*

*Article available as Open Access

PubMed link: http://www.ncbi.nlm.nih.gov/pubmed/20981513


Written by Sungho Hong, Computational Neuroscience Unit, Okinawa Institute of Science and Technology, 2009.
Contact: Sungho Hong (shhong@oist.jp)

Suffix from newCaP to Cav2_1


ENDCOMMENT

COMMENT
11 Apr 2021
Edits by Suranjana Gupta (SG)
Removed dependency of temp. on temp. correction factor.
Hard-coded 6.3 degC

Also, corrected 'E' to 'Em'
Em is a pre-defined constant in NEURON

h.E         2.71828182845904523536
https://www.neuron.yale.edu/neuron/static/py_doc/programming/math/constants.html

ghk() already present in orig. code. No changes made here
ENDCOMMENT



INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}

NEURON {
    SUFFIX ch_Cacna1a_md229585
    USEION ca READ cai, cao WRITE ica
    RANGE pcabar, ica, gk, vhalfm, cvm, vshift, taum, minf, Em
}

UNITS {
    (mV) = (millivolt)
    (mA) = (milliamp)
    (nA) = (nanoamp)
    (pA) = (picoamp)
    (S)  = (siemens)
    (nS) = (nanosiemens)
    (pS) = (picosiemens)
    (um) = (micron)
    (molar) = (1/liter)
    (mM) = (millimolar) 
    FARADAY = (faraday) (coulomb)   :SG
    R = (k-mole) (joule/degC)       : SG -> it is actually J/K-mole but won't compile if units are changed    
}

CONSTANT {
    q10 = 3
    :SG
    :F = 9.6485e4 (coulombs)
    :R = 8.3145 (joule/kelvin)
}

PARAMETER {
    v (mV)
    celsius (degC)

    cai (mM)
    cao (mM)

    vhalfm = -29.458 (mV)
    cvm = 8.429(mV)
    vhalfh = -11.039 (mV)
    cvh = 16.098 (mV)
    vshift = 0 (mV)

    pcabar = 2.2e-4 (cm/s)
}

ASSIGNED {
    qt
    ica (mA/cm2)
    minf
    taum (ms)
    gk (coulombs/cm3)
    T (kelvin)
    :E (volt)       :SG
    Em (volt)       :SG
    zeta
}

STATE { m }

INITIAL {
    :qt = q10^((celsius-23 (degC))/10 (degC))
    qt = q10^((6.3-23 (degC))/10 (degC))
    T = kelvinfkt( celsius )
    rates(v)
    m = minf
}

BREAKPOINT {
    SOLVE states METHOD cnexp
    
    ica = (1e3) * pcabar * m * m * m * gk
}

DERIVATIVE states {
    rates(v)
    m' = (minf-m)/taum
}

FUNCTION ghk( v (mV), ci (mM), co (mM), z )  (coulombs/cm3) { 
    :E = (1e-3) * v
    Em = (1e-3) * v
    zeta = (z*FARADAY*Em)/(R*T)  
    
    if ( fabs(1-exp(-zeta)) < 1e-6 ) {
        ghk = (1e-6) * (z*FARADAY) * (ci - co*exp(-zeta)) * (1 + zeta/2)
    } else {
        ghk = (1e-6) * (z*zeta*FARADAY) * (ci - co*exp(-zeta)) / (1-exp(-zeta))
    }
}

PROCEDURE rates( v (mV) ) {

    minf = 1 / ( 1 + exp(-(v-vhalfm-vshift)/cvm) )

    taum = taumfkt(v-vshift)/qt
    
    gk = ghk(v-vshift, cai, cao, 2)
}


FUNCTION kelvinfkt( t (degC) )  (kelvin) {
    UNITSOFF
    kelvinfkt = 273.19 + t
    UNITSON
}

FUNCTION taumfkt( v (mV) ) (ms) {
    UNITSOFF
    if (v>=-40) {
        taumfkt = 0.2702 + 1.1622 * exp(-(v+26.798)*(v+26.798)/164.19)
    } else {
        taumfkt = 0.6923 * exp(v/1089.372)
    }
    UNITSON
}







