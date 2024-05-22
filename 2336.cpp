#include<set>
using namespace std;
class SmallestInfiniteSet {
    int start;
    set<int> st;
public:

    SmallestInfiniteSet() {
        start=1;
    }
    
    int popSmallest() {
        if(st.empty()){
            start++;
            return start-1;
        }
        else{
            int s=*st.begin();
            if(s<start){
                st.erase(st.begin());
                return s;
            }
            else{
                start++;
                return start-1;
            }
        }
    }
    void addBack(int num) {
        if (num<start){
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */