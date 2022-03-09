#pragma once

#if !defined (PLATFORM_WINDOWS)
	#define PLATFORM_WINDOWS 0
#endif

// CPU ISAs
#ifndef PLATFORM_CPU_X86_FAMILY
	#if (defined(_M_IX86) || defined(__i386__) || defined(_M_X64) || defined(__amd64__) || defined(__x86_64__))
		#define PLATFORM_CPU_X86_FAMILY	1
	#else
		#define PLATFORM_CPU_X86_FAMILY	0
	#endif
#endif

#ifndef PLATFORM_CPU_ARM_FAMILY
	#if (defined(__arm__) || defined(_M_ARM) || defined(__aarch64__) || defined(_M_ARM64))
		#define PLATFORM_CPU_ARM_FAMILY	1
	#else
		#define PLATFORM_CPU_ARM_FAMILY	0
	#endif
#endif

// Memory features
#ifndef CPU_MEMORY_ALIGNMENT
	#define CPU_MEMORY_ALIGNMENT 4
#endif 

#ifndef GPU_MEMORY_ALIGNMENT
	#define GPU_MEMORY_ALIGNMENT 512
#endif 

// TODO: Vector Intrinsics

// TODO: Compiler features

// TODO: graphics features
// - gles
// - borderless window
// half float vertex
// special shaders
// tocuh screen