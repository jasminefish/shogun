/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2011 Shashwat Lal Das
 * Copyright (C) 2011 Berlin Institute of Technology and Max-Planck-Society
 *
 * This file demonstrates how a regular CSimpleFeatures object can
 * be used as input for the StreamingFeatures framework, effectively
 * making it suitable for using online learning algorithms.
 */

#include <shogun/features/StreamingSimpleFeatures.h>
#include <shogun/io/StreamingFileFromSimpleFeatures.h>

#include <shogun/mathematics/Math.h>
#include <shogun/lib/common.h>
#include <shogun/io/SGIO.h>
#include <shogun/base/init.h>

#include <stdlib.h>
#include <stdio.h>

using namespace shogun;

#define NUM 100
#define DIMS 2
#define DIST 0.5

float32_t* feat;
float64_t* lab;

void gen_rand_data()
{
	feat=SG_MALLOC(float32_t, NUM*DIMS);
	lab=SG_MALLOC(float64_t, NUM);

	for (int32_t i=0; i<NUM; i++)
	{
		if (i<NUM/2)
		{
			for (int32_t j=0; j<DIMS; j++)
				feat[i*DIMS+j]=CMath::random(0.0,1.0)+DIST;
			lab[i]=0;
		}
		else
		{
			for (int32_t j=0; j<DIMS; j++)
				feat[i*DIMS+j]=CMath::random(0.0,1.0)-DIST;
			lab[i]=1;
		}
	}
	CMath::display_matrix(feat,DIMS, NUM);
}

int main()
{
	init_shogun_with_defaults();

	// Generate random data, features and labels
	gen_rand_data();

	// Create features
	CSimpleFeatures<float32_t>* features = new CSimpleFeatures<float32_t>();
	SG_REF(features);
	features->set_feature_matrix(feat, DIMS, NUM);

	// Create a StreamingSimpleFeatures object which uses the above as input; labels (float64_t*) are optional
	CStreamingSimpleFeatures<float32_t>* streaming_simple = new CStreamingSimpleFeatures<float32_t>(features, lab);
	SG_REF(streaming_simple);

	// Start parsing of the examples; in this case, it is trivial - returns each vector from the SimpleFeatures object
	streaming_simple->start_parser();

	int32_t counter=0;
	SG_SPRINT("Processing examples...\n\n");

	// Run a while loop over all the examples.  Note that since
	// features are "streaming", there is no predefined
	// number_of_vectors known to the StreamingFeatures object.
	// Thus, this loop must be used to iterate over all the
	// features
	while (streaming_simple->get_next_example())
	{
		counter++;
		// Get the current vector; no other vector is accessible
		SGVector<float32_t> vec = streaming_simple->get_vector();
		float64_t label = streaming_simple->get_label();

		SG_SPRINT("Vector %d: [\t", counter);
		for (int32_t i=0; i<vec.vlen; i++)
		{
			SG_SPRINT("%f\t", vec.vector[i]);
		}
		SG_SPRINT("Label=%f\t", label);

		// Calculate dot product of the current vector (from
		// the StreamingFeatures object) with itself (the
		// vector passed as argument)
		float32_t dot_prod = streaming_simple->dense_dot(vec.vector, vec.vlen);

		SG_SPRINT("]\nDot product of the vector with itself: %f", dot_prod);
		SG_SPRINT("\n\n");

		// Free the example, since we are done with processing it.
		streaming_simple->release_example();
	}

	// Now that all examples are used, end the parser.
	streaming_simple->end_parser();

	SG_FREE(lab);

	SG_UNREF(streaming_simple);
	SG_UNREF(features);

	exit_shogun();
	return 0;
}
