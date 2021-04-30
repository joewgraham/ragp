:[$URL: https://bbpteam.epfl.ch/svn/analysis/trunk/IonChannel/xmlTomod/CreateMOD.c $]
:[$Revision: 1499 $]
:[$Date: 2012-01-28 10:45:44 +0100 (Sat, 28 Jan 2012) $]
:[$Author: rajnish $]
:Comment :
:Reference :Subunit-specific modulation of T-type calcium channels by zinc. J. Physiol. (Lond.), 2007, 578, 159-71

COMMENT
Edits by Suranjana Gupta (SG): eca computed by adding ghk()
ghk() has been added from: 
https://senselab.med.yale.edu/modeldb/ShowModel?model=168874&file=/ca1dDemo/cal_mig.mod#tabs-2
ENDCOMMENT

NEURON	{
	SUFFIX ch_Cacna1i_cp42
	:USEION ca READ eca WRITE ica 			:SG
	USEION ca READ cai, cao WRITE ica 		:SG
	RANGE gCav3_3bar, gCav3_3, ica, BBiD 
	RANGE ggk								:SG
	GLOBAL USEGHK							:SG
}

UNITS	{
	(S) = (siemens)
	(mV) = (millivolt)
	(mA) = (milliamp)
}

PARAMETER	{
	gCav3_3bar = 0.00001 (S/cm2) 
	BBiD = 87 
	:SG
	cai = 50.e-6 (mM)
  	cao = 2 (mM)
  	USEGHK=1
}

ASSIGNED	{
	v	(mV)
	eca	(mV)
	ica	(mA/cm2)
	gCav3_3	(S/cm2)
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
	gCav3_3 = gCav3_3bar*m*h
	:Added by SG
	if(USEGHK ==1)	{
		ggk = ghk(v,cai,cao)
	} else {
		ggk = (v-eca)
	}
	ica = gCav3_3*ggk
	:ica = gCav3_3*(v-eca)			:SG
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
		mInf = 1/(1+exp((v- -45.454426)/-5.073015)) 
		mTau = 3.394938 +( 54.187616 / (1 + exp((v - -40.040397)/4.110392))) 
		hInf = 1 /(1+exp((v-(-74.031965))/8.416382)) 
		hTau = 109.701136 + (0.003816 * exp(-v/4.781719))
	UNITSON
}
