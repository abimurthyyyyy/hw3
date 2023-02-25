#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap;
	int m;
	PComparator c;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
	this->m = m;
  this ->c = c;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){
	
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("nothing at top");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap[0];
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
	return heap.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
	return heap.size();
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("nothing to pop");
  }
  std::swap(heap[0], heap[heap.size()-1]);
	heap.pop_back();
	if (heap.size()<2){
		return;
	}
	int parent = 0;
	int prio = 1;
	while(true){
		for (int i = 1; i<=m;i++){
			int cand = i+m*parent;
			if (cand<heap.size()){
				if (c(heap[cand], heap[prio])){
					prio = cand;
				}
			}
		}
		if (!c(heap[parent], heap[prio])){
			std::swap(heap[parent], heap[prio]);
			parent = prio;
      prio = 1+m*parent;
      if (prio>=heap.size()){
        break;
      }
		}
		else{
			break;
		}
	}
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
	heap.push_back(item);
	int loc = heap.size()-1;
	while (c(heap[loc],heap[(loc-1)/m])){
		std::swap(heap[loc],heap[(loc-1)/m]);
		loc = (loc-1)/m;
		if (loc ==0){
			break;
		}
	}
}






#endif
