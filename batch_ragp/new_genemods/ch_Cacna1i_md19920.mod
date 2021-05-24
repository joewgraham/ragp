COMMENT 
11 Apr 2021
Edits by Suranjana Gupta (SG): eca computed by adding ghk()

Original code computed eca by employing GHK voltage equation (in carev)
Replaced carev with ghk() equation which incorporates the GHK current equation in:
https://senselab.med.yale.edu/modeldb/showmodel.cshtml?model=136095&file=%2fncdemo%2fil.mod#tabs-2

USEGHK (and associated codes) have been added (mm) along the format in:
https://senselab.med.yale.edu/modeldb/ShowModel?model=168874&file=/ca1dDemo/cal_mig.mod#tabs-2
ENDCOMMENT




TITLE CaT channel alpha-1I from McRory et al, 2001
: Reversal potential described by Nernst equation
: M.Migliore Jan 2003

UNITS {
	(mA) = (milliamp)
	(mV) = (millivolt)
	(molar) = (1/liter)
	(mM) = (millimolar)
	FARADAY = (faraday) (coulomb)
	R = (k-mole) (joule/degC)	:: SG -> it is actually J/K-mole but won't compile if units are changed
}

PARAMETER {
	v (mV)
	:celsius		(degC)		:SG
	gbar=.008 (mho/cm2)
    vhalfn=-60.7   (mV)
    vhalfl=-93.2   (mV)
    kn=8.39   (1)
    kl=-5.4   (1)
	q10=2.3
	cai 	= .00005 (mM)	: initial [Ca]i = 50 nM
	cao 	= 2	(mM)	: [Ca]o = 2 mM
	eca (mV)
	:SG
  	USEGHK=1
}


NEURON {
	SUFFIX ch_Cacna1i_md19920
	:USEION ca READ eca WRITE ica		:SG
	USEION ca READ cai, cao WRITE ica 		:SG mm
    RANGE gbar, carev
    GLOBAL ninf,linf,taul,taun, q10
    RANGE ggk								:SG mm
	GLOBAL USEGHK							:SG mm
}

STATE {
	n
        l
}

ASSIGNED {
	ica	(mA/cm2)		: current
	carev	(mV)			: rev potential
        ninf
        linf      
        taul
        taun
    :SG
	ggk		
	celsius 	(degC)
}

INITIAL {
	rates(v)
	n=ninf
	l=linf
}


BREAKPOINT {
	SOLVE states METHOD cnexp
	:Added by SG
	if(USEGHK ==1)	{
		ggk = ghk(v,cai,cao,celsius)
	} else {
		ggk = (v-eca)
	}
	ica = gbar*n*l*ggk
	:carev = (1e3) * (R*(celsius+273.15))/(2*FARADAY) * log (cao/cai)
	:ica = gbar*n*l*(v-carev)
}


DERIVATIVE states {     : exact when v held constant; integrates over dt step
        rates(v)
        n' = (ninf - n)/taun
        l' =  (linf - l)/taul
}

UNITSOFF 
PROCEDURE rates(v (mV)) { :callable from hoc
        LOCAL a,qt
        :qt=q10^((celsius-22)/10)
        qt=q10^((6.3-22)/10)				:SG
        ninf = 1/(1 + exp(-(v-vhalfn)/kn))
        linf = 1/(1 + exp(-(v-vhalfl)/kl))
        taun = (2.71+0.028*exp(-v/9.34))/qt
        taul = (110+0.0009*exp(-v/5.16))/qt
}

:Two Functions added by SG
FUNCTION ghk(v(mV), ci(mM), co(mM),celsius(degC)) (.001 coul/cm3) {
	LOCAL z, eci, eco
	z = (1e-3)*2*FARADAY*v/(R*(celsius+273.15))
	eco = co*efun(z)
	eci = ci*efun(-z)
	:high cao charge moves inward
	:negative potential charge moves inward
	ghk = (.001)*2*FARADAY*(eci - eco)
}

FUNCTION efun(z) {
	if (fabs(z) < 1e-4) {
		efun = 1 - z/2
	}else{
		efun = z/(exp(z) - 1)
	}
}
UNITSON


















