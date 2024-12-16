#include <cstdlib>
#include <iostream>
// #include<ctime>

using namespace std;

const int maxLevels = 6;

struct skipNode{
	int item;
	skipNode** forward;
	// The forward array of skipNode* contains connections to all nodes below current node and forward to it.
	
	skipNode(int level, int value){
		forward = new skipNode*[level + 1];
		// We do level+1 because we assume level starts from 0. Hence, if a node is at 0 level we create a forward
		// array of skipNode* of length 1 containing all the nodes ahead of this node
		this->item = value;
		for (int i = 0; i <= level; i++) forward[i] = nullptr;
	}

	~skipNode(){
		delete[] forward;
	}
};

class skipList{
	int maxLevel;
	int level;
	skipNode* head;

public:
	skipList(int m = maxLevels) : maxLevel(m), level(0){
		// On initialization we generate a head that is a skipnode of maximum levels to accomodate all.
		head = new skipNode(m, -1);
	}
	~skipList(){
		delete head;
	}

	int randomLevel(){
		float r = (float) rand()/RAND_MAX;
		int lvl = 0;
		while (r < 0.5 && lvl < maxLevel){
			lvl++;
			r = (float) rand()/RAND_MAX;
		}
		return lvl;
	}

	void insert(int x){
		skipNode* cur = head;
		skipNode** update = new skipNode*[maxLevel+1];
		for (int i = 0; i <= maxLevel; i++) update[i] = nullptr;

		for (int i = level; i >= 0; i--){
			// This loop is basically us traversing through a level until we find cur->next/forward (at ith level obv) having val < x.
			// Then we get value at cur to be highest value less than x
			while(cur->forward[i] && cur->forward[i]->item < x){
				cur = cur->forward[i];	
			}
			// The update array will basically maintain where we had to switch levels on each level.
			update[i] = cur;
		}
		
		cur = cur->forward[0]; // Finally cur was at loc just before where x is to be inserted. So we shift it to next or forward node just to ease insertion
		
		if (cur == nullptr || cur->item != x){
			int newNodeLevel = randomLevel();

			if (newNodeLevel > level){
				// Essentially we connect update[i] with head as logically for a new Level a direct connection from head is done.
				for (int i = level + 1; i < newNodeLevel + 1; i++) update[i] = head;
				level = newNodeLevel;
			}

			skipNode* newNode = new skipNode(newNodeLevel, x);
			for (int i = 0; i <= newNodeLevel; i++){
				newNode->forward[i] = update[i]->forward[i]; // newNode's next at ith level becomes the next of update at ith level
				update[i]->forward[i] = newNode; // update's next at ith level becomes newNode
			}
		}

		delete[] update;
	}

	bool search(int x){
		skipNode* cur = head;
		
		for (int i = level; i >= 0; i--){
			while (cur->forward[i] && cur->forward[i]->item < x) cur = cur->forward[i];
		}
		cur = cur->forward[0];

		return (cur != nullptr && cur->item == x);
	}

	void del(int x){
		skipNode* cur = head;
		skipNode** update = new skipNode*[maxLevel+1];
		
		for (int i = level; i >= 0; i--){
			while (cur->forward[i] && cur->forward[i]->item < x) cur = cur->forward[i];
			update[i] = cur;
		}
		cur = cur->forward[0];

		if (cur != nullptr && cur->item == x){
			for (int i = 0; i <= level; i++){
				if (update[i]->forward[i] != cur) break; // This simply means the next of updates further is not connected to current but bypasses it
				update[i]->forward[i] = cur->forward[i];
			}

			delete cur;

			// We might also need to update our level.
			while (level > 0 && head->forward[level] == nullptr) level--;
		}

	}
};

int main(){
	// srand((unsigned)time(0));
    skipList list(3);

    // Insert some elements
    list.insert(3);
    list.insert(6);
    list.insert(7);
    list.insert(9);
    list.insert(12);
    list.insert(19);
    list.insert(17);
    list.insert(26);
    list.insert(21);
    list.insert(25);
    list.insert(29);
    list.insert(34);
    list.insert(37);
    list.insert(45);
    list.insert(52);
    list.insert(62);
    list.insert(75);
    list.insert(68);
    list.insert(70);
    list.insert(80);
    list.insert(85);
    list.insert(96);
    list.insert(99);

    // Search for an element
    int searchValue = 100;

	if (list.search(searchValue)){
		std::cout << "Element " << searchValue << " found in Skip List." << std::endl;
	}
	else {
        std::cout << "Element " << searchValue << " not found in Skip List." << std::endl;
	}
    return 0;
}
