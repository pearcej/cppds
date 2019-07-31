..  Copyright (C)  Brad Miller, David Ranum, and Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.


Binary Heap Operations
----------------------

The basic operations we will implement for our binary heap are as
follows:

-  ``BinaryHeap()`` creates a new, empty, binary heap.

-  ``insert(k)`` adds a new item to the heap.

-  ``findMin()`` returns the item with the minimum key value, leaving
   item in the heap.

-  ``delMin()`` returns the item with the minimum key value, removing
   the item from the heap.

-  ``isEmpty()`` returns true if the heap is empty, false otherwise.

-  ``size()`` returns the number of items in the heap.

-  ``buildHeap(vector)`` builds a new heap from a vector of keys.

:ref:`ActiveCode 1 <lst_heap1>` demonstrates the use of some of the binary
heap methods.  Notice that no matter the order that we add items to the heap, the smallest
is removed each time.  We will now turn our attention to creating an implementation for this idea.

.. _lst_heap1:

.. tabbed:: heap1

  .. tab:: C++

    .. activecode:: heap1cpp
        :caption: Using the Binary Heap C++
        :language: cpp

        #include <iostream>
        #include <vector>
        using namespace std;

        class BinHeap{

        private:
            vector<int> heapvector;
            int currentSize;

        public:
            BinHeap(vector<int> heapvector){
                this->heapvector = heapvector;
                this->currentSize = 0;
            }

            void percUp(int i){
                while ((i / 2) > 0){
                    if (this->heapvector[i] < this->heapvector[i/2]){
                        int tmp = this->heapvector[i/2];
                        this->heapvector[i/2] = this->heapvector[i];
                        this->heapvector[i] = tmp;
                    }
                    i = i/2;
                }

            }

            void insert(int k){
                this->heapvector.push_back(k);
                this->currentSize = this->currentSize + 1;
                this->percUp(this->currentSize);
            }

            void percDown(int i){
                while ((i*2) <= this->currentSize){
                    int mc = this->minChild(i);
                    if (this->heapvector[i] > this->heapvector[mc]){
                        int tmp = this->heapvector[i];
                        this->heapvector[i] = this->heapvector[mc];
                        this->heapvector[mc] = tmp;
                    }
                    i = mc;
                }
            }

            int minChild(int i){
                if (((i*2)+1) > this->currentSize){
                    return i * 2;
                }
                else{
                    if (this->heapvector[i*2] < this->heapvector[(i*2)+1]){
                        return i * 2;
                    }
                    else{
                        return (i * 2) + 1;
                    }
                }
            }

            int delMin(){
                int retval = this->heapvector[1];
                this->heapvector[1] = this->heapvector[this->currentSize];
                this->currentSize = this->currentSize - 1;
                this->heapvector.pop_back();
                this->percDown(1);
                return retval;
            }

            void buildheap(vector<int> avector){
                int i = avector.size() / 2;
                this->currentSize = avector.size();
                this->heapvector.insert(this->heapvector.end(), avector.begin(), avector.end());
                while (i > 0){
                    this->percDown(i);
                    i = i - 1;
                }
            }

            bool isEmpty(){
                if (this->heapvector.size()>0){
                    return false;
                }
                return true;
            }

            int findMin(){
                return this->heapvector[1];
            }
        };


        int main(){
            int arr[] = {9, 5, 6, 2, 3};
            vector<int> a(arr,arr+(sizeof(arr)/ sizeof(arr[0])));

            vector<int> vec;
            vec.push_back(0);

            BinHeap *bh = new BinHeap(vec);

            bh->insert(5);
            bh->insert(7);
            bh->insert(3);
            bh->insert(11);

            cout << bh->delMin() << endl;
            cout << bh->delMin() << endl;
            cout << bh->delMin() << endl;
            cout << bh->delMin() << endl;

            return 0;
        }

  .. tab:: Python

    .. activecode:: heap1py
        :caption: Using the Binary Heap Python

        #you can use the command below to import the binheap library:
        #from pythonds.trees.binheap import BinHeap

        class BinHeap:

            def __init__(self, heaparray):
                self.heaparray = heaparray
                self.size = 0

            def percUp(self, i):
                while ((i//2) > 0):
                    if(self.heaparray[i] < self.heaparray[i//2]):
                        temp = self.heaparray[i//2]
                        self.heaparray[i//2] = self.heaparray[i]
                        self.heaparray[i] = temp
                    i = i//2

            def insert(self, k):
                self.heaparray.append(k)
                self.size += 1
                self.percUp(self.size)

            def percDown(self, i): 
                while (i*2) <= self.size:
                    mc = self.minChild(i)
                    if self.heaparray[i] > self.heaparray[mc]:
                        temp = self.heaparray[i]
                        self.heaparray[i] = self.heaparray[mc]
                        self.heaparray[mc] = temp
                    i = mc

            def minChild(self, i):
                if ((i*2)+1) > self.size:
                    return i*2;
                else:
                    if self.heaparray[i*2] < self.heaparray[(i*2)+1]:
                        return i*2
                    else:
                        return (i*2) + 1

            def delMin(self):
                retval = self.heaparray[1]
                self.heaparray[1] = self.heaparray[self.size]
                self.size = self.size - 1
                del self.heaparray[-1]
                self.percDown(1)
                return retval   

            def buildheap(self, alist):
                # might be wrong
                i = len(alist) / 2
                self.size = len(alist)
                self.heaparray.insert(self.heaparray[-1], alist[0], alist[-1])
                while i > 0:
                    self.perdDown(i)
                    i -= 1

            def isEmpty(self):
                if len(self.heaparray) > 0:
                    return False;
                return True

            def findMin(self):
                return self.heaparray[1]

        def main():
            alist = []
            alist.append(0) #required for indexing in the class methods!!

            bh = BinHeap(alist);

            bh.insert(5);
            bh.insert(7); 
            bh.insert(3);
            bh.insert(11);

            print(bh.delMin())
            print(bh.delMin())
            print(bh.delMin())
            print(bh.delMin())

        main()
