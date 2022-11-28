/* 
A set of code examples from the C++ Wisard of Esker. 
Thanks to Jean-Marc Dambrosio for sharing some code examples with me
*/

#define fowardToImpl(fun) makeMeUnique(pimpl)->fun

// pimpl = private implementation
	template<class _Type>
	class ASDKLIB impl_ptr {
		size_t use_count() const;
		bool unique() const;
	};
	
template<class _Type> inline bool impl_ptr<_Type>::unique() const { return use_count() == 1; }

	template<class _Ty, class... _Types>
	inline impl_ptr<_Ty> make_impl(_Types&&... _Args) {
		return impl_ptr<_Ty>(new _Ty(std::forward<_Types>(_Args)...));
	}
	
	
namespace asdk {
	template<class className>
	inline impl_ptr<className> duplicate(impl_ptr<className>& pimpl) {
		// use copy constructor
		return make_impl<className>(*pimpl);
		// use duplicate method
		//	pimpl = asdk::impl_ptr<className>(pimpl->duplicate());
	}

	template<class className>
	inline impl_ptr<className>& makeMeUnique(impl_ptr<className>& pimpl) {
		if (!pimpl.unique()) {
			pimpl = duplicate(pimpl);
			pimpl->assignImplPtr(pimpl);
		}
		return pimpl;
	}

	template<class className>
	inline const impl_ptr<className>& makeMeUnique(const impl_ptr<className>& pimpl) {
		return pimpl;
	}
};
