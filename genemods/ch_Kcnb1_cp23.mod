:[$URL: https://bbpteam.epfl.ch/svn/analysis/trunk/IonChannel/xmlTomod/CreateMOD.c $]
:[$Revision: 1499 $]
:[$Date: 2012-01-28 10:45:44 +0100 (Sat, 28 Jan 2012) $]
:[$Author: rajnish $]
:Comment :
:Reference :Alteration and restoration of K+ channel function by deletions at the N- and C-termini. Neuron, 1990, 5, 433-43

NEURON	{
	SUFFIX ch_Kcnb1_cp23
	USEION k READ ek WRITE ik
	RANGE gKv2_1bar, gKv2_1, ik, BBiD 
}

UNITS	{
	(S) = (siemens)
	(mV) = (millivolt)
	(mA) = (milliamp)
}

PARAMETER	{
	gKv2_1bar = 0.00001 (S/cm2) 
	BBiD = 23 
}

ASSIGNED	{
	v	(mV)
	ek	(mV)
	ik	(mA/cm2)
	gKv2_1	(S/cm2)
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
	gKv2_1 = gKv2_1bar*m*h
	ik = gKv2_1*(v-ek)
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
		mInf = 1/(1+exp(((v -(-9.200))/(-6.600)))) 
		mTau = 100.000/(1+exp(((v -(-46.560))/(44.140)))) 
		hInf = 1/(1+exp(((v -(-19.000))/(5.000)))) 
		hTau = 10000.000/(1+exp(((v -(-46.560))/(-44.140))))
	UNITSON
}