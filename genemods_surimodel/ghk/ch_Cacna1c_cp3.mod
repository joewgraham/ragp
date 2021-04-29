:[$URL: https://bbpteam.epfl.ch/svn/analysis/trunk/IonChannel/xmlTomod/CreateMOD.c $]
:[$Revision: 1499 $]
:[$Date: 2012-01-28 10:45:44 +0100 (Sat, 28 Jan 2012) $]
:[$Author: rajnish $]
:Comment :
:Reference :Multiple channel types contribute to the low-voltage-activated calcium current in hippocampal CA3 pyramidal neurons. J. Neurosci., 1996, 16, 5567-82

COMMENT
Edits by Suranjana Gupta (SG): eca computed by adding ghk()

ghk() has been added from:
https://senselab.med.yale.edu/modeldb/ShowModel?model=168874&file=/ca1dDemo/cal_mig.mod#tabs-2
ENDCOMMENT

NEURON	{
	SUFFIX ch_Cacna1c_cp3
	:USEION ca READ eca WRITE ica 			:SG
	USEION ca READ cai, cao WRITE ica 		:SG
	RANGE gLbar, gL, ica, BBiD 
	RANGE ggk								:SG
	GLOBAL USEGHK							:SG
}

UNITS	{
	(S) = (siemens)
	(mV) = (millivolt)
	(mA) = (milliamp)
}

PARAMETER	{
	gLbar = 0.00001 (S/cm2) 
	BBiD = 212 
	:SG
	cai = 50.e-6 (mM)
  	cao = 2 (mM)
  	USEGHK=1
}

ASSIGNED	{
	v	(mV)
	eca	(mV)
	ica	(mA/cm2)
	gL	(S/cm2)
	mInf
	mTau
	hInf
	hTau
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
	gL = gLbar*m*m*h
	:Added by SG
	if(USEGHK ==1)	{
		ggk = ghk(v,cai,cao)
	} else {
		ggk = (v-eca)
	}
	ica = gL*ggk
	:ica = gL*(v-eca)			:SG
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
		mInf = 1.0000/(1+ exp((v - -30.000)/-6)) 
		mTau = 10 
		hInf = 1.0000/(1+ exp((v - -80.000)/6.4)) 
		hTau = 59
	UNITSON
}
