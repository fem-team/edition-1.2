/*****************************************************************************/
/*  STAP++ : A C++ FEM code sharing the same input data file with STAP90     */
/*     Computational Dynamics Laboratory                                     */
/*     School of Aerospace Engineering, Tsinghua University                  */
/*                                                                           */
/*     Release 1.11, November 22, 2017                                       */
/*                                                                           */
/*     http://www.comdyn.cn/                                                 */
/*****************************************************************************/

#pragma once

#include "Element.h"

using namespace std;

//! 4Q element class
class C3T : public CElement
{
public:

	//!	Constructor
	C3T();

	//!	Desconstructor
	~C3T();

	//!	Read element data from stream Input
	virtual bool Read(ifstream& Input, unsigned int Ele, CMaterial* MaterialSets, CNode* NodeList);

	//!	Write element data to stream
	virtual void Write(COutputter& output, unsigned int Ele);

	//! Generate location matrix: the global equation number that corresponding to each DOF of the element
	//	Caution:  Equation number is numbered from 1 !
	virtual void GenerateLocationMatrix();

	//!	Calculate element stiffness matrix
	virtual void ElementStiffness(double* Matrix);

	//!	Calculate element stiffness matrix 
	//virtual void ElementMass(double* Mass);

	//!	Calculate element stress
	virtual void ElementStress(double* stress, double* Displacement);

	// Caculate Gravity of Elements
	virtual double Gravity() ;

	//!	Calculate element stress for plot

	//!	Return the size of the element stiffness matrix (stored as an array column by column)
	virtual unsigned int SizeOfStiffnessMatrix();

	virtual void ElementPostInfo(double* stress, double* Displacement, double* PrePositions,double* PostPositions);
};
#pragma once
