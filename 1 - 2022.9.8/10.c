typedef int DATA_TYPE;
typedef struct Node {
    DATA_TYPE data;
    struct Node *LChild;
    struct Node *RChild;
} BiTNode, *BiTree;
int cntLeaf(BiTree root) {
    int sumLeaf;
    if (root == NULL) sumLeaf = 0;
    else if((root->LChild == NULL)&&(root->RChild == NULL)) sumLeaf=1;
    else sumLea = cntLeaf(root->LChild) + cntLeaf(root->RChild);
    return sumLeaf;
}