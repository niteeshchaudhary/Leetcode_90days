#include <iostream>
class TwoThreeTree
{
public:
    TwoThreeTree() :
        root_(nullptr)
    {}

    TwoThreeTree(const TwoThreeTree& src) = delete;
    //TwoThreeTree(TwoThreeTree&& src) noexcept;

    TwoThreeTree& operator= (const TwoThreeTree& src) = delete;
    //TwoThreeTree& operator= (TwoThreeTree&& src) noexcept;

    //virtual ~TwoThreeTree();

    bool insert(const int& key);
    bool searchKey(const int& key) const;
    bool deleteKey(const int& key);

    //void printAll() const;

    struct Node
    {
        Node* parent;
        int* keys;
        int keyCount;
        Node** children;
        int childrenCount;

        std::string* translations;
        int translationCount;

        Node() :
            parent{nullptr},
            keyCount(0),
            childrenCount(0),
            translationCount(0)
        {
            keys = new int[3] {-842150451, -842150451, -842150451};//заглушка
            children = new Node* [4];
            for (int i = 0; i < 4; i++)
            {
                children[i] = nullptr;
            }
            translations = nullptr;
        }

        Node(const Node& src) :
            parent(src.parent),
            keyCount(src.keyCount),
            childrenCount(src.childrenCount),
            translationCount(src.translationCount),
            translations(nullptr)//-------------
        {
            keys = new int[3];
            for (int i = 0; i < 3; i++)
            {
                keys[i] = src.keys[i];
            }
            children = new Node * [4];
            for (int i = 0; i < 4; i++)
            {
                children[i] = src.children[i];
            }
            for (int i = 0; i < src.translationCount; i++)
            {
                translations = nullptr;//------------
            }
        }

        ~Node()
        {
            delete[] keys;
            delete[] children;
            delete[] translations;
        }

        void sortChildren()
        {
            if (childrenCount == 1)
            {
                return;
            }
            if (childrenCount == 2)
            {
                if (children[0]->keys[0] > children[1]->keys[0])
                {
                    std::swap(children[0], children[1]);
                }
            }
            else if (childrenCount == 3)
            {
                if (children[0]->keys[0] > children[1]->keys[0])
                {
                    std::swap(children[0], children[1]);
                }
                if (children[0]->keys[0] > children[2]->keys[0])
                {
                    std::swap(children[0], children[2]);
                }
                if (children[1]->keys[0] > children[2]->keys[0])
                {
                    std::swap(children[1], children[2]);
                }
            }
            else if (childrenCount == 4)
            {
                if (children[0]->keys[0] > children[1]->keys[0])
                {
                    std::swap(children[0], children[1]);
                }
                if (children[0]->keys[0] > children[2]->keys[0])
                {
                    std::swap(children[0], children[2]);
                }
                if (children[0]->keys[0] > children[3]->keys[0])
                {
                    std::swap(children[0], children[3]);
                }
                if (children[1]->keys[0] > children[2]->keys[0])
                {
                    std::swap(children[1], children[2]);
                }
                if (children[1]->keys[0] > children[3]->keys[0])
                {
                    std::swap(children[1], children[3]);
                }
                if (children[2]->keys[0] > children[3]->keys[0])
                {
                    std::swap(children[2], children[3]);
                }
            }
        }
    };

    Node* root_{ nullptr };

    Node* searchNode(const int& key) const;
    bool deleteNode(Node* node, const int& key);
    void printTree(Node* node, int level);
    void splitParent(Node* node);
    void updateKeys(Node* node);

    int maxKey(Node* node) const;

    //void remove(Node* node);
};

bool TwoThreeTree::insert(const int& key)
{
    Node* n = new Node;
    n->keys[0] = key;
    n->keyCount++;
    if (root_ == nullptr)
    {
        std::cout<<key<<std::endl;
        root_ = n;
        return true;
    }

    Node* a = searchNode(key);
    if (a->parent == nullptr)
    {
        Node* t = new Node(*root_);
        root_->children[0] = t;
        root_->children[1] = n;
        t->parent = root_;
        n->parent = root_;
        root_->childrenCount = 2;
        root_->sortChildren();
        //printTree(root_,0);
        for(int i = 1; i < 4; i++)
        {
            std::cout << "Search " << i << ": " << searchKey(i) << std::endl;
        }

        std::cout<<"___\n";
    }
    else
    {
        Node* p = a->parent;
        p->children[p->childrenCount] = n;
        p->childrenCount++;
        n->parent = p;
        p->sortChildren();
        updateKeys(n);
        splitParent(n);
        for(int i = 1; i < key; i++)
        {
            std::cout << "Search " << i << ": " << searchKey(i) << std::endl;
        }

        std::cout<<"___\n";
    }
    updateKeys(n);
    
    return true;
}

void TwoThreeTree::splitParent(Node* node)
{
    if(node->childrenCount > 3)
    {
        Node* a = new Node;
        a->keys[0] = node->keys[1];
        a->keyCount++;
        a->parent = node->parent;
        a->childrenCount = 2;
        a->children[0] = node->children[2];
        a->children[1] = node->children[3];

        node->children[2]->parent = a;
        node->children[3]->parent = a;
        node->childrenCount = 2;
        node->children[2] = nullptr;
        node->children[3] = nullptr;

        if (node->parent != nullptr)
        {
            node->parent->children[node->childrenCount] = a;
            node->childrenCount++;
            node->parent->sortChildren();
            splitParent(node->parent);
        }
        else
        {
            Node* t = new Node(*root_);
            root_->children[0] = t;
            root_->children[1] = a;
            t->parent = root_;
            a->parent = root_;
            root_->childrenCount = 2;
            root_->sortChildren();
        }
    }
}

void TwoThreeTree::updateKeys(Node* node)
{
    Node* a = node->parent;
    while (a != nullptr)
    {
        for (int i = 0; i < a->childrenCount - 1; i++)
        {
            a->keys[i] = maxKey(a->children[i]);
        }
        a = a->parent;
    }
}

int TwoThreeTree::maxKey(Node* node) const
{
    Node* current = node;
    while (current->childrenCount != 0)
    {
        if (current->childrenCount == 3)
        {
            current = current->children[2];
        }
        else
        {
            current = current->children[1];
        }
    }

    return current->keys[0];
}

bool TwoThreeTree::searchKey(const int& key) const
{
    return searchNode(key)->keys[0] == key;
}

TwoThreeTree::Node* TwoThreeTree::searchNode(const int& key) const
{
    Node* t = root_;
    while (t->childrenCount != 0)
    {
        if (t->childrenCount == 2)
        {
            if (t->keys[0] < key)
            {
                t = t->children[1];
            }
            else
            {
                t = t->children[0];
            }
        }
        else if (t->keys[1] < key)
        {
            t = t->children[2];
        }
        else if (t->keys[0] < key)
        {
            t = t->children[1];
        }
        else
        {
            t = t->children[0];
        }
    }
    return t;
}

bool TwoThreeTree::deleteKey(const int& key)
{
    return false;
}

bool TwoThreeTree::deleteNode(Node* node, const int& key)
{
    return false;
}

void TwoThreeTree::printTree(Node* node, int level = 0) {
        if (node == nullptr) return;

        for (int i = 0; i < level; ++i) {
            std::cout << "  ";
        }

        for (int i = 0; i < node->keyCount; ++i) {
            std::cout << node->keys[i] << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < node->childrenCount; ++i) {
            printTree(node->children[i], level + 1);
        }
    }

int main() {
    TwoThreeTree tree;
    int arr[] = { 1,2,3,4,5,6 };
    for(int i = 0; i < 6; i++)
    {
        tree.insert(arr[i]);
    }

    // Optionally, you can add code to verify the structure of the tree
    // For example, search for keys and print results
    for(int i = 0; i < 6; i++)
    {
        std::cout << "Search " << arr[i] << ": " << tree.searchKey(arr[i]) << std::endl;
    }

    tree.printTree(tree.root_);

    return 0;
}