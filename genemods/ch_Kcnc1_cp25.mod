:[$URL: https://bbpteam.epfl.ch/svn/analysis/trunk/IonChannel/xmlTomod/CreateMOD.c $]
:[$Revision: 1499 $]
:[$Date: 2012-01-28 10:45:44 +0100 (Sat, 28 Jan 2012) $]
:[$Author: rajnish $]
:Comment :
:Reference :Characterization of a Shaw-related potassium channel family in rat brain. EMBO J., 1992, 11, 2473-86

NEURON	{
	SUFFIX ch_Kcnc1_cp25
	USEION k READ ek WRITE ik
	RANGE gKv3_1bar, gKv3_1, ik, BBiD 
}

UNITS	{
	(S) = (siemens)
	(mV) = (millivolt)
	(mA) = (milliamp)
}

PARAMETER	{
	gKv3_1bar = 0.00001 (S/cm2) 
	BBiD = 25 
}

ASSIGNED	{
	v	(mV)
	ek	(mV)
	ik	(mA/cm2)
	gKv3_1	(S/cm2)
	mInf
	mTau
}

STATE	{ 
	m
}

BREAKPOINT	{
	SOLVE states METHOD cnexp
	gKv3_1 = gKv3_1bar*m
	ik = gKv3_1*(v-ek)
}

DERIVATIVE states	{
	rates()
	m' = (mInf-m)/mTau
}

INITIAL{
	rates()
	m = mInf
}

PROCEDURE rates(){
	UNITSOFF 
		mInf = 1/(1+exp(((v -(18.700))/(-9.700)))) 
		mTau = 20.000/(1+exp(((v -(-46.560))/(-44.140))))
	UNITSON
}
