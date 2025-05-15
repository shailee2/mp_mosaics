/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

template <int Dim>
bool smallerDimVal(const Point<Dim>& first, const Point<Dim>& second, int curDim)
{
    /**
     * @todo Implement this function!
     */
     if (curDim > (Dim - 1) || curDim < 0){
      return false;
     }
     if (first[curDim] > second[curDim]){ //first does not have a smaller value
      return false;
     }
     else if (first[curDim] < second[curDim]){ //first does have a smaller value
      return true;
     }
     else{
      return first < second; //there is a tie
     }
}

template <int Dim>
bool shouldReplace(const Point<Dim>& target, const Point<Dim>& currentBest, const Point<Dim>& potential)
{
    /**
     * @todo Implement this function!
     */
     //new variables to manipulate
     double cb = 0;
     double p = 0;
     //for each dimension, add together the squared distances
     for (int i = 0; i < Dim; i++){
      cb += (currentBest[i] - target[i]) * (currentBest[i] - target[i]);
      p += (potential[i] - target[i]) * (potential[i] - target[i]);
     }
     //check if this is a better option
     if (p < cb){
      return true;
     }
     else if (cb < p){
      return false;
     }
     //tie
     return potential < currentBest;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    vector<Point<Dim>> points;
    points.assign(newPoints.begin(), newPoints.end()); //copies the list
    root = maketree(points, 0, 0, points.size() - 1);
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::maketree(vector<Point<Dim>>& points, int dimension, int left, int right){
  size = 0;
  if (points.empty()){
    return nullptr;
  }
  if (left > right){
    return nullptr;
  }
  int dim = dimension % Dim;
  int middle = (left + right) / 2;
  select(points.begin() + left, points.begin() + right + 1, points.begin() + middle, [dim](const Point<Dim>& a, const Point<Dim>& b){
    return smallerDimVal(a, b, dim);
  });
  KDTreeNode * node = new KDTreeNode(points[middle]);
  node->left = maketree(points, dim, left, middle - 1);
  node->right = maketree(points, dim, middle + 1, right);
  return node;
}


template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
   copy(other.root);
   size = other.size;
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::copy(const KDTreeNode* root) {
  if (root != nullptr){
    KDTreeNode* newnode = new KDTreeNode(root->point);
    newnode->left = copy(root->left);
    newnode->right = copy(root->right);
  }
  else{
    return nullptr;
  }
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  if (this != &rhs){
  clear(root);
  root = copy(rhs.root);
  size = rhs.size;}
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
   clear(root);
}

template <int Dim>
void KDTree<Dim>::clear(KDTreeNode* root){
  if (root == nullptr){
    return;
   }
   clear(root->left);
   clear(root->right);
   delete root;
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    return Point<Dim>();
}

template <typename RandIter, typename Comparator>
void select(RandIter start, RandIter end, RandIter k, Comparator cmp)
{
    /**
     * @todo Implement this function!
     */    
}

