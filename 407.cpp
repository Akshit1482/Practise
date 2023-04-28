class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        
        // constructor
        TrieNode( char ch ){
            data = ch;
            for( int i=0; i<26; i++ ){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;
        
        //constructor
        Trie(){
            root = new TrieNode('\0');
        }
        
        // insertion code
        void insertUtil( TrieNode* root, string word ){
            // base case
            if( word.length() == 0 ){
                root->isTerminal = true;
                return;
            }
            
            // assuming all charcter are small
            int index = word[0] - 'a';
            TrieNode* child;
            
            // if root has child
            if( root->children[index] != NULL ){
                child = root->children[index];
            }
            else{  // absent
                child = new TrieNode( word[0] );
                root->children[index] = child;
            }
            // recursion
            insertUtil( child, word.substr(1));
        }
        
        void insertWord( string word ){
            insertUtil( root, word );
        }
        
        void printSuggestions( TrieNode* curr, vector<string>& temp, string prefix ){
            // base case
            if( curr->isTerminal ){
                temp.push_back( prefix );
            }
            
            for( char ch = 'a'; ch <= 'z'; ch++ ){
                TrieNode* next = curr->children[ ch - 'a' ];
                
                if( next != NULL ){  // if any child is found
                    prefix.push_back( ch );
                    printSuggestions( next, temp, prefix );
                    prefix.pop_back();
                }
            }
        }
        
        vector<vector<string>> getSuggestions( string str ){
            TrieNode* prev = root;  // creating prev to track the traversal
            vector<vector<string>> output;
            string prefix = "";
            int i =0;
            for( int i =0; i<str.length(); i++){
                char lastch = str[i];
                
                prefix.push_back( lastch );
                // check for lastch children
                TrieNode* curr = prev->children[lastch - 'a'];
                
                // if child not found
                if( curr == NULL ){
                    break;
                }
                // if found
                vector<string>temp;
                printSuggestions( curr, temp, prefix );
                
                output.push_back( temp );
                temp.clear();
                prev = curr; // move prev forward for traversal
            }
            // this is for adding 0, when suggestion not found
            if( i< str.size() ){
                while( i< str.size() ){
                    output.push_back({"0"});
                    i++;
                }
            }
            return output;
        }
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // creation of TRIE
        Trie* t = new Trie();
        
        // insert all elements in the trie
        for( int i =0; i<n; i++ ){
            string str = contact[i];
            t->insertWord( str );
        }
        
        //return ans
        return t->getSuggestions( s );
    }
};
