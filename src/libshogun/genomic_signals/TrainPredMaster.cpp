#include <stdio.h>
#include <string.h>

#include "lib/Mathematics.h"
#include "lib/config.h"
#include "lib/io.h"
#include "genomic_signals/TrainPredMaster.h"
#include "genomic_signals/KernelFactory.h"
#define MAXLINE 1000

using namespace shogun;


CTrainPredMaster::CTrainPredMaster(CGUIKernel* p_ui_kernel)
:CSGObject(), kernelplist(NULL)
{
	ui_kernel = p_ui_kernel;
	SG_REF(ui_kernel);
}
CTrainPredMaster::~CTrainPredMaster()
{
	SG_UNREF(ui_kernel);
}
void CTrainPredMaster::read_models_from_file(char* filename)
{
	FILE* pFile;
	pFile = fopen (filename , "r");
	if (!pFile)
               SG_ERROR("Error opening file\n");	
	char line   [MAXLINE];
	char name   [MAXLINE];
	char value   [MAXLINE];
	int32_t num_read=0, nofkernels=0, nofmodels=1;
	char* fgets_ret;
	while (!feof(pFile))
	{
		// read line of config file
		///////////////////////////////////
		fgets_ret = fgets(line, MAXLINE, pFile);
		if (!fgets_ret)
			break;
		if (line[0]=='%')
			continue;

		// scan name and value from line
		///////////////////////////////////////
		num_read = sscanf(line, "%s\t%s", name, value);

		if (num_read<0)
			continue;

		SG_PRINT("name:%s value:%s\n", name, value);

		// parse value depending on the name
		////////////////////////////////////////
		if (strcmp(name, "kernelname")==0)
		{
			SG_PRINT("kernel name:%s\n", value);
			nofkernels++;
			// enlarge the list of kernels by one
			/////////////////////////////////////////
			CKernelFactory** kernelplist_tmp = new CKernelFactory*[nofkernels];
			for (int32_t i=0; i<nofkernels-1; i++)
				kernelplist_tmp[i] = kernelplist[i];
			delete [] kernelplist;
			kernelplist = kernelplist_tmp;

			// append new kernel to the list
			///////////////////////////////////////
			kernelplist[nofkernels-1] = new CKernelFactory();
			kernelplist[nofkernels-1]->set_kernelname(value);
			
		}
		else 
		{
			int32_t ivalue[6];
			num_read = sscanf(value, "%i,%i,%i,%i,%i,%i,%i,%i", &ivalue[0], &ivalue[1], &ivalue[2], &ivalue[3], &ivalue[4], &ivalue[5]);
			if (num_read < 1)
				SG_ERROR("Error scaning value\n");
			else if (num_read > 5)// one more would also be possible, but then I cannot determine if the maximal number was exeeded
				SG_ERROR("To many model selection values given\n");
			else if (num_read>1)
				SG_ERROR("not yet implemented\n");

			nofmodels*=num_read;
			for (int32_t i=0; i<num_read; i++)
				SG_PRINT("%i  ", ivalue[i]);
			SG_PRINT("\n");
		}
	
	}	
	SG_PRINT("number of models:%i\n", nofmodels);
	fclose(pFile);
}


