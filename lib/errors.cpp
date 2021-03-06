/*
 * OpenCL tools
 *
 * Copyright (C) 2011 Yusuke Suzuki 
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */
#include "errors.hpp"

#if !APPLE
	#include <CL/cl.h>
#else
	#include <OpenCL/opencl.h>
#endif

#ifndef CL_INVALID_PROPERTY                         
	#define CL_INVALID_PROPERTY                         -64
#endif

namespace OCLT
{

#define iMAP_ELEM(X) std::map<int, std::string>::value_type(X , #X)

static const std::map<int, std::string>::value_type iErrorMessages[] =
{
	iMAP_ELEM(CL_SUCCESS),
	iMAP_ELEM(CL_DEVICE_NOT_FOUND),
	iMAP_ELEM(CL_DEVICE_NOT_AVAILABLE),
	iMAP_ELEM(CL_COMPILER_NOT_AVAILABLE),
	iMAP_ELEM(CL_MEM_OBJECT_ALLOCATION_FAILURE),
	iMAP_ELEM(CL_OUT_OF_RESOURCES),
	iMAP_ELEM(CL_OUT_OF_HOST_MEMORY),
	iMAP_ELEM(CL_PROFILING_INFO_NOT_AVAILABLE),
	iMAP_ELEM(CL_MEM_COPY_OVERLAP),
	iMAP_ELEM(CL_IMAGE_FORMAT_MISMATCH),
	iMAP_ELEM(CL_IMAGE_FORMAT_NOT_SUPPORTED),
	iMAP_ELEM(CL_BUILD_PROGRAM_FAILURE),
	iMAP_ELEM(CL_MAP_FAILURE),
	iMAP_ELEM(CL_MISALIGNED_SUB_BUFFER_OFFSET),
	iMAP_ELEM(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST),

	iMAP_ELEM(CL_INVALID_VALUE),
	iMAP_ELEM(CL_INVALID_DEVICE_TYPE),
	iMAP_ELEM(CL_INVALID_PLATFORM),
	iMAP_ELEM(CL_INVALID_DEVICE),
	iMAP_ELEM(CL_INVALID_CONTEXT),
	iMAP_ELEM(CL_INVALID_QUEUE_PROPERTIES),
	iMAP_ELEM(CL_INVALID_COMMAND_QUEUE),
	iMAP_ELEM(CL_INVALID_HOST_PTR),
	iMAP_ELEM(CL_INVALID_MEM_OBJECT),
	iMAP_ELEM(CL_INVALID_IMAGE_FORMAT_DESCRIPTOR),
	iMAP_ELEM(CL_INVALID_IMAGE_SIZE),
	iMAP_ELEM(CL_INVALID_SAMPLER),
	iMAP_ELEM(CL_INVALID_BINARY),
	iMAP_ELEM(CL_INVALID_BUILD_OPTIONS),
	iMAP_ELEM(CL_INVALID_PROGRAM),
	iMAP_ELEM(CL_INVALID_PROGRAM_EXECUTABLE),
	iMAP_ELEM(CL_INVALID_KERNEL_NAME),
	iMAP_ELEM(CL_INVALID_KERNEL_DEFINITION),
	iMAP_ELEM(CL_INVALID_KERNEL),
	iMAP_ELEM(CL_INVALID_ARG_INDEX),
	iMAP_ELEM(CL_INVALID_ARG_VALUE),
	iMAP_ELEM(CL_INVALID_ARG_SIZE),
	iMAP_ELEM(CL_INVALID_KERNEL_ARGS),
	iMAP_ELEM(CL_INVALID_WORK_DIMENSION),
	iMAP_ELEM(CL_INVALID_WORK_GROUP_SIZE),
	iMAP_ELEM(CL_INVALID_WORK_ITEM_SIZE),
	iMAP_ELEM(CL_INVALID_GLOBAL_OFFSET),
	iMAP_ELEM(CL_INVALID_EVENT_WAIT_LIST),
	iMAP_ELEM(CL_INVALID_EVENT),
	iMAP_ELEM(CL_INVALID_OPERATION),
	iMAP_ELEM(CL_INVALID_GL_OBJECT),
	iMAP_ELEM(CL_INVALID_BUFFER_SIZE),
	iMAP_ELEM(CL_INVALID_MIP_LEVEL),
	iMAP_ELEM(CL_INVALID_GLOBAL_WORK_SIZE),
	iMAP_ELEM(CL_INVALID_PROPERTY),
};

static const size_t iErrorMessageMapSize =
	sizeof(iErrorMessages) / sizeof(iErrorMessages[0]);
const std::map<int, std::string> ErrorMessageMap(
	iErrorMessages, iErrorMessages + iErrorMessageMapSize);

}

