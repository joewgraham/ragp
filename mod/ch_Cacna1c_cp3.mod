:[$URL: https://bbpteam.epfl.ch/svn/analysis/trunk/IonChannel/xmlTomod/CreateMOD.c $]
:[$Revision: 1499 $]
:[$Date: 2012-01-28 10:45:44 +0100 (Sat, 28 Jan 2012) $]
:[$Author: rajnish $]
:Comment : L-type Calcium channel
:Reference :Multiple channel types contribute to the low-voltage-activated calcium current in hippocampal CA3 pyramidal neurons. J. Neurosci., 1996, 16, 5567-82

NEURON	{
	SUFFIX ch_Cacna1c_cp3
	USEION ca READ eca WRITE ica
	RANGE gLbar, gL, ica, BBiD 
}

UNITS	{
	(S) = (siemens)
	(mV) = (millivolt)
	(mA) = (milliamp)
}

PARAMETER	{
	gLbar = 0.00001 (S/cm2) 
	BBiD = 212 
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
}

STATE	{ 
	m
	h
}

BREAKPOINT	{
	SOLVE states METHOD cnexp
	gL = gLbar*m*m*h
	ica = gL*(v-eca)
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
