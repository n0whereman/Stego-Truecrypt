/*
 Copyright (c) 2008 TrueCrypt Developers Association. All rights reserved.

 Governed by the TrueCrypt License 3.0 the full text of which is contained in
 the file License.txt included in TrueCrypt binary and source code distribution
 packages.
*/

#ifndef TC_HEADER_Encoder_EncoderAlgorithm
#define TC_HEADER_Encoder_EncoderAlgorithm
#include "Encoders/HammingEncoder.h"
 #include "Encoders/LsbEncoder.h"
#include "Platform/Platform.h"

namespace TrueCrypt 
{
	class EncoderAlgorithm;
	typedef list < shared_ptr <Encoder> > EncoderAlgorithmList;

	class EncoderAlgorithm
	{
	public:
		virtual ~EncoderAlgorithm ();		
		static EncoderAlgorithmList GetAvailableAlgorithms ();
		virtual shared_ptr <Encoder> GetNew () const = 0;
		bool IsDeprecated () const { return Deprecated; }

	protected:
		EncoderAlgorithm ();
		void ValidateState () const;
		bool Deprecated;
				

	private:
		EncoderAlgorithm (const EncoderAlgorithm &);
		EncoderAlgorithm &operator= (const EncoderAlgorithm &);
	};


/*#define TC_ENCODER_ALGORITHM(NAME) \
	class NAME : public EncoderAlgorithm \
	{ \
	public: \
		NAME (); \
		virtual ~NAME () { } \
\
		virtual shared_ptr <Encoder> GetNew () const { return shared_ptr <Encoder> (new NAME()); } \
\
	private: \
		NAME (const NAME &); \
		NAME &operator= (const NAME &); \
	}

	TC_ENCODER_ALGORITHM (HammingEncoder);
	TC_ENCODER_ALGORITHM (LsbEncoder);

*/
#undef TC_ENCODER_ALGORITHM
}

#endif // TC_HEADER_Encoder_EncoderAlgorithm
