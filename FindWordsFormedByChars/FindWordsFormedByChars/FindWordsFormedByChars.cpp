// FindWordsFormedByChars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr auto ALPH = 26;
static const int CHARSET = 26;

typedef struct TrieNode
{
    TrieNode* Child[ALPH];
    // isLeaf is true if the node represents 
    // end of a word 
    bool leaf;
}TrieNode;

TrieNode* AllocNode(void);
void insert(TrieNode* root, string);
void searchWord(TrieNode* root, bool Hash[], string str, int& len);
int PrintAllWords(string Arr, TrieNode* root, int n);


int main()
{
    vector<string> words = { "cat", "bt", "hat", "tree" };
    string chars = "atach";
    int num = words.size();
    int N = chars.length();
    // Build Trie
    int total = 0;
    TrieNode* root = AllocNode();

    for (string s : words)
    {
        insert(root, s);
    }
    // Print all words
    cout << "Total Length " << PrintAllWords(chars, root, N) << endl;
    //std::cout << "Hello World!\n";
}

TrieNode* AllocNode(void)
{
    TrieNode* newNode = new TrieNode();
    newNode->leaf = false;

    for (int i = 0; i < ALPH; i++)
        newNode->Child[i] = nullptr;
    return newNode;
}

void insert(TrieNode* root, string Key)
{
    int n = Key.length();
    TrieNode* pChild = root;

    for (int i = 0; i < n; i++)
    {
        int index = Key[i]-'a';

        if (pChild->Child[index] == NULL)
            pChild->Child[index] = AllocNode();

        pChild = pChild->Child[index];
    }

    // make last node as leaf node 
    pChild->leaf = true;
}

void searchWord(TrieNode* root, bool Hash[], string str,int& len)
{
    // if we found word in trie / dictionary 
    if (root->leaf == true)
    {
        len += str.length();
        cout << str << endl;
        return;
    }
 
    // traverse all child's of current root 
    for (int K = 0; K < ALPH; K++)
    {
        if (Hash[K] == true && root->Child[K] != NULL)
        {
            // add current character 
            char c = K + 'a';

            // Recursively search reaming character of word 
            // in trie 
            searchWord(root->Child[K], Hash, str + c,len);
        }
    }
}

int PrintAllWords(string Arr, TrieNode* root, int n)
{
    // create a 'has' array that will store all present 
    // character in Arr[] 
    bool Hash[ALPH] = { 0 };

    for (int i = 0; i < n; i++)
        Hash[Arr[i]-'a'] = true;
    int len = 0;
    // tempary node 
    TrieNode* pChild = root;

    // string to hold output words 
    string str = "";

    // Traverse all matrix elements. There are only 26 
    // character possible in char array 
    for (int i = 0; i < ALPH; i++)
    {
        // we start searching for word in dictionary 
        // if we found a character which is child 
        // of Trie root 
        if (Hash[i] == true && pChild->Child[i])
        {
            str = str + (char)(i +'a');
            searchWord(pChild->Child[i], Hash, str,len);
            str = "";
        }
    }

    return len;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
