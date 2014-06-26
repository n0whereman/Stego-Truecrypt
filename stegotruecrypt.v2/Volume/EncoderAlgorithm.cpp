/*
 Copyright (c) 2008 TrueCrypt Developers Association. All rights reserved.

 Governed by the TrueCrypt License 3.0 the full text of which is contained in
 the file License.txt included in TrueCrypt binary and source code distribution
 packages.
*/

#include "EncoderAlgorithm.h"
#include "Encoders/EncoderFactory.h"
#include <vector>
namespace TrueCrypt
{
	EncoderAlgorithm::EncoderAlgorithm () : Deprecated (false)
	{
	}

	EncoderAlgorithm::~EncoderAlgorithm ()
	{
	}

	

	EncoderAlgorithmList EncoderAlgorithm::GetAvailableAlgorithms ()
	{
	    std::vector<EncoderPtr> v = EncoderFactory::getEncoders();

		EncoderAlgorithmList l;
		
		for (auto it = v.begin(); it != v.end();  it++ )
		{   
       		l.push_back (*it);
		}                                      
		return l;
	}

		
	
	
	

}
