#pragma once

// Allocator.h: Heirarchical memory allocation design
// Top level is page, each page has whatever allocator is best for it's subsystem
// All allocators are std friendly, but not ISO guaranteed

#include "../Core.h"

// TODO: On debug builds, warn if an allocator goes out of scope before all memory has been freed
// TODO: Test

// virtual is okay since allocations are not frequently called per frame

enum AllocatorFlags : int32_t
{
	None = 0,
	FirstFind = 0x1,
	BestFind = 0x2
};

class Allocator
{
	Allocator(const std::size_t totalSize) : TotalSize{ totalSize }, Used{ 0 }, Peak{ 0 } { }

	virtual ~Allocator() { TotalSize = 0; }

	virtual void* Allocate(const std::size_t size, const std::size_t alignment = 0, AllocatorFlags flags = AllocatorFlags::None) = 0;

	virtual void Free(void* ptr) = 0;

	virtual void Init() = 0;

private:
	std::size_t TotalSize;
	std::size_t Used;
	std::size_t Peak;
};

class LinearAllocator : public Allocator
{
public:
	LinearAllocator(const std::size_t TotalSize);

	virtual ~LinearAllocator();

	virtual void* Allocate(const std::size_t size, const std::size_t alignment = 0, AllocatorFlags flags = AllocatorFlags::None) override;

	virtual void Free(void* ptr) override;

	virtual void Init() override;

protected:
	LinearAllocator(LinearAllocator& allocator);
	void* start_ptr = nullptr;
	std::size_t offset;
};


//
//template <typename T>
//class TrackingAllocator
//{
//public:
//	using value_type = T;
//
//	using ptr_type = T*;
//	using const_ptr_type = const T*;
//	using void_ptr_type = void*;
//	using const_void_ptr_type = const void*;
//
//	using size_type = size_t;
//	using difference_type = std::ptrdiff_t;
//
//	TrackingAllocator() = default;
//	~TrackingAllocator() = default;
//
//	ptr_type allocate(size_type n)
//	{
//		return static_cast<ptr_type>(operator new(sizeof(T) * n));
//	}
//
//	// allocate two object next to each other for cache contiguity
//	ptr_type allocate(size_type n, const_void_ptr_type hint)
//	{
//		return allocate(n);
//	}
//
//	void deallocate(ptr_type p, size_type n)
//	{
//		operator delete(p);
//	}
//
//	size_type max_size() const
//	{
//		return std::numeric_limits<size_type>::max();
//	}
//
//	template<class U, class... Args>
//	void construct(U* p, Args && ...args)
//	{
//		new(p) U(std::forward<Args>(args)...);
//	}
//
//	template<class U>
//	void destroy(U* p)
//	{
//		p->~U();
//	}
//};