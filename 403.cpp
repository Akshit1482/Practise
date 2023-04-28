// User function template for C++

// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    // base case
    if( key.length() == 0 ){
        root->isLeaf = true;
        return;
    }
    
    // all words are in small
    int index = key[0] - 'a';
    TrieNode* child;
    
    // if child present
    if( root -> children[ index ] != NULL ){
        child = root->children[index];  // children is found , so move forward
    }
    else{  // absent
        child = new TrieNode();
        root -> children[ index ] = child;
    }
    // recursion
    insert( child, key.substr(1));
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    // base case
    if( key.length() == 0 ){
        return root->isLeaf;
    }
    
    // all words are in small
    int index = key[0] - 'a';
    TrieNode* child;
    
    // if child is present
    if( root -> children[ index ] != NULL ){
        child = root->children[index];
    }
    else{  // absent
        child = new TrieNode();
        return false;  // as if we have not traversed the whole key, and we haven't found the terminal node, thus the key is mot ppresent
    }
    
    // recursion
    return search( child, key.substr(1));
}
