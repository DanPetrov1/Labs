//
// Created by danpe on 07.11.2019.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

template <class T>
struct Node {
    T data;
    Node* parent;
    Node* left;
    Node* right;
};

template <class T>
class BinaryTree {
private:
    Node<T>* root;
public:
    BinaryTree() { root = nullptr; }
    ~BinaryTree() { }

    bool insert(T data);
    bool find(T data);
    Node<T>* getNodeByValue(T data);
    T min();
    T max();
    void output();
    void remove(Node<T>* value);
    bool deleteByValue(T value);
    void deleteAll();
    void deleteAllNodes(Node<T>* value);

    template<class T>
    class Iterator {
        Node<T> *current;
    public:
        Iterator() { current = nullptr; }

        Iterator(Iterator &iter) { current = iter.current; }
        ~Iterator() = default;
        // Получение узла из итератора
        Node<T>* getNode() { return current; }
        // Функции сдвига итератора
        bool operator++() {
            if (current == nullptr) return false;
            if (current->right) {
                current = current->right;
                while (current->left) {
                    current = current->left;
                }
            } else {
                current = current->parent;
            }
            return true;
        }

        bool operator--() {
            if (current->parent == nullptr) return false;
            if (current->left) {
                current = current->left;
            } else {
                while (current->parent->left == current) {
                    current = current->parent;
                }
                current = current->parent;
            }
            return true;
        }
        // Получение значения из итератора
        T& operator*() {return current->data; }
        // Операторы сравнения для итератора
        bool operator==(Iterator &iter) {
            if (current == nullptr && iter.current == nullptr)
                return true;
            if (current == nullptr || iter.current == nullptr)
                return false;
            if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
                return true;
            return false;
        }

        bool operator!=(Iterator &iter) {
            if (current == nullptr && iter.current == nullptr)
                return false;
            if ((current == nullptr && iter.current != nullptr) || (current != nullptr && iter.current == nullptr))
                return true;
            if (current->data == iter.current->data && current->next == iter.current->next && current->prev == iter.current->prev)
                return false;
            return true;
        }

        Node<T>* begin() {
            return min();
        }

        Node<T>* end() {
            return (max())->right;
        }
    };
};

template<class T>
bool BinaryTree<T>::insert(T data) {
    Node *buffer = new Node;
    buffer->data = data;
    buffer->left = buffer->right = buffer->parent = nullptr;
    if (!root) {
        root = buffer;
    }
    Node *current = root;
    while (current) {
        if (data < current->data) {
            if (current->left) {
                current = current->left;
            } else {
                current->left = buffer;
                buffer->parent = current;
                return true;
            }
        } else if (data > current->data) {
            if (current->right) {
                current = current->right;
            } else {
                current->right = buffer;
                buffer->parent = current;
                return true;
            }
        } else {
            return false;
        }
    }
    return false;
}

template<class T>
bool BinaryTree<T>::find(T data) {
    Node* current = root;
    while (current) {
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            return true;
        }
    }
    return false;
}

template<class T>
T BinaryTree<T>::min() {
    Node* current = root;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

template<class T>
T BinaryTree<T>::max() {
    Node* current = root;
    while (current && current->right) {
        current = current->right;
    }
    return current;
}

template<class T>
Node<T> *BinaryTree<T>::getNodeByValue(T data) {
    Node* current = root;
    while (current) {
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            return current;
        }
    }
    return nullptr;
}

template<class T>
void BinaryTree<T>::remove(Node<T> *value) {
    if (value->left && value->right) {
        Node<T> *buffer = value->left;
        while (buffer->right) {
            buffer = buffer->right;
        }
        value->data = buffer->data;
        remove(buffer);
        return;
    }
    else if (value->left) {
        if (value == value->parent->left)
            value->parent->left = value->left;
        else
            value->parent->right = value->left;
    }
    else if (value->right) {
        if (value == value->parent->right)
            value->parent->right = value->right;
        else
            value->parent->left = value->right;
    }
    else {
        if (value->parent->right == value)
            value->parent->right = NULL;
        else
            value->parent->left = NULL;
    }
    delete (value);
}

template<class T>
bool BinaryTree<T>::deleteByValue(T value) {
    Node<T> *buffer = getNodeByValue(value);
    if (!buffer)
        return false;
    remove(buffer);
    return true;
}

template<class T>
void BinaryTree<T>::deleteAll() {
    deleteAllNodes(root);
}

template<class T>
void BinaryTree<T>::deleteAllNodes(Node<T> *value) {
    if (value->left) {
        deleteAllNodes(value->left);
    }
    if (value->right) {
        deleteAllNodes(value->right);
    }
    delete (value);
}

template<class T>
void BinaryTree<T>::output() {
    for (Node<T>* current = begin(); current++;) {
        std::cout << current << std::endl;
    }
}

#endif //BINARYTREE_BINARYTREE_H
