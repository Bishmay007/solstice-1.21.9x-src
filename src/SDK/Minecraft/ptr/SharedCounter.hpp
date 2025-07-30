#pragma once

template <typename T>
class SharedCounter {
public:
	explicit SharedCounter(T* p = nullptr) : ptr(p), share_count(1), weak_count(0) {}

	void addShareCount() { share_count++; }

	void addWeakCount() { weak_count++; }

	int getShareCount() const { return share_count.load(); }

	int getWeakCount() const { return weak_count.load(); }

	T* get() const { return ptr; }

	void release() {
		if (--share_count == 0) {
			delete ptr;
			ptr = nullptr;
			if (weak_count == 0) {
				delete this;
			}
		}
	}

	void releaseWeak() {
		if (--weak_count == 0 && share_count == 0) {
			delete this;
		}
	}

	T* ptr;
	std::atomic_int share_count;
	std::atomic_int weak_count;
};
