/*! \file driver.cpp
\brief Driver file to execute the 1 D Range Query on a set of data points.
It calls the function to determine the convex hull which are implemented in algorithm.h file. It includes iostream, math.h, string, set, cstring, vector, fstream, sstream, cstdlib, algorithm,locale header files and bbst.h header file.
*/

#include <iostream>
#include <math.h>
#include <string>
#include <set>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <locale> 
#include "bbst.h"


using namespace std;

int main()
{
	//instance of BSST class.
	BBST s;
	
	//instance of BSSTNode class.
	BBSTNode *t;
	
	float i, xLower, xUpper;
	bool check;
	
	//float vector to contain all the values in the range.
	vector< float > range;
	vector< float >::iterator iter;

	//upper and lower range values are taken from user.
	cin >> xLower;
	cin >> xUpper;
			
	if(xLower > xUpper)
	{
		cout << "Error: Give correct input values for xLower and xUpper" << endl;	
		exit(0);
	}
	
	    //input values taken from a random generator.
    	while (cin >> i) 
    	{
    		s.insert(i);
    	}
    	
    	//print the balanced binary search tree using preorder traversal.
    	cout << endl << "Values entered in the BBST: " << endl << endl;	
    	s.preorder();
    	cout << endl << endl;
    	
    	if(xLower == xUpper)
	{
		check = s.search(xUpper);
		if(check)
			cout << xUpper << endl;
		else
			cout << "No values found in the given range" << endl << endl;
		exit(0);
	}
	
	//find the split node for given xlower and xupper.
    	t = s.findSplitNode(xLower, xUpper);
    	cout << endl << " Split node: " << t->data << endl << endl;
    	
    	if(((t->left)==NULL)&&((t->right)==NULL))
    	{
    		if((t->data >= xLower)&&(t->data <= xUpper))
    			range.push_back(t->data);
    	}
    	else
    	{
    		range.push_back(t->data);
    		s.followLower(xLower, t, range);
    		s.followUpper(xUpper, t, range);
    	}
    	
        iter = unique (range.begin(), range.end());
	range.resize( distance(range.begin(),iter) );
    	sort(range.begin(), range.end());
    	
    	if(range.empty())
    	{
    		cout << "No values found in the given range" << endl << endl; 
    		exit(0);
    	}
    	
    	cout << "Values found in the given range "<< xLower <<" & "<< xUpper << " : " << endl << endl;
	
	//output the values from input within the range specified by xlower and xupper.
	for (iter=range.begin() ; iter != range.end(); ++iter)
    		cout << *iter << " ";
    		
  	cout << endl << endl;	
}

