:[$URL: https://bbpteam.epfl.ch/svn/analysis/trunk/IonChannel/xmlTomod/CreateMOD.c $]
:[$Revision: 1499 $]
:[$Date: 2012-01-28 10:45:44 +0100 (Sat, 28 Jan 2012) $]
:[$Author: rajnish $]
:Comment :
:Reference :Activation and inactivation properties of voltage-gated calcium currents in developing cat retinal ganglion cells. Neuroscience, 1998, 85, 239-47

COMMENT
Edits by Suranjana Gupta (SG): eca computed by adding ghk()

ghk() has been added from:
https://senselab.med.yale.edu/modeldb/ShowModel?model=168874&file=/ca1dDemo/cal_mig.mod#tabs-2
ENDCOMMENT

NEURON	{
	SUFFIX ch_Cacna1b_cp6
	:USEION ca READ eca WRITE ica 			:SG
	USEION ca READ cai, cao WRITE ica 		:SG
	RANGE gCav2_2bar, gCav2_2, ica, BBiD 
	RANGE ggk								:SG
	GLOBAL USEGHK							:SG
}

UNITS	{
	(S) = (siemens)
	(mV) = (millivolt)
	(mA) = (milliamp)
}

PARAMETER	{
	gCav2_2bar = 0.00001 (S/cm2) 
	BBiD = 79 
	:SG
	cai = 50.e-6 (mM)
  	cao = 2 (mM)
  	USEGHK=1
}

ASSIGNED	{
	v	(mV)
	eca	(mV)
	ica	(mA/cm2)
	gCav2_2	(S/cm2)
	mInf
	mTau
	mAlpha
	mBeta
	hInf
	hTau
	hAlpha
	hBeta
	:SG
	ggk		
	celsius 	(degC)	
}

STATE	{ 
	m
	h
}

BREAKPOINT	{
	SOLVE states METHOD cnexp
	gCav2_2 = gCav2_2bar*m*m*h
	:Added by SG
	if(USEGHK ==1)	{
		ggk = ghk(v,cai,cao)
	} else {
		ggk = (v-eca)
	}
	ica = gCav2_2*ggk
	:ica = gCav2_2*(v-eca)			:SG
}

:Two Functions added by SG
FUNCTION ghk(v(mV), ci(mM), co(mM)) (mV) {
	LOCAL numr, deno
	deno = ((25./293.15)*(celsius + 273.15))/2
	numr = v/deno
	ghk=-deno*(1. - (ci/co)*exp(numr))*efun(numr)
}

FUNCTION efun(z) {
  if (fabs(z) < 1e-4) {
    efun = 1 - z/2
  }else{
    efun = z/(exp(z) - 1)
  }
}

DERIVATIVE states	{
	rates()
	m' = (mInf-m)/mTau
	h' = (hInf-h)/hTau
}

INITIAL{
	rates()
	m = mInf
	h = hInf
}

PROCEDURE rates(){
	UNITSOFF
		if(v == 20){
			v = v + 0.000001
		}
		mAlpha = (0.1*(v-20)/(1-exp(-(v-20)/10))) 
		mBeta = 0.4*exp(-(v+25)/18)
		mInf = mAlpha/(mAlpha + mBeta)
		mTau = 1/(mAlpha + mBeta) 
		hAlpha = 0.01*exp(-(v+50)/10) 
		hBeta = 0.1/(1+exp(-(v+17)/17))
		hInf = hAlpha/(hAlpha + hBeta)
		hTau = 1/(hAlpha + hBeta)
	UNITSON
}
