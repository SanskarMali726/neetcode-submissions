/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// ============================================================
// EXAMPLE TREE we'll trace through in the comments below:
//
//         2
//        / \
//       1   3
//          / \
//         1   5     <-- this "1" is the tricky one, should be INVALID
//
// Why invalid? Because it's in the RIGHT subtree of 2,
// so it must be > 2. But its value is 1, which is NOT > 2.
// Even though 1 < 3 (its direct parent), that's not enough —
// it also has to obey grandparent 2's rule. That's the whole point
// of carrying "low" and "upper" down through the recursion.
// ============================================================

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // Start with NO restrictions: any value is allowed at the root.
        // low  = "everything must be BIGGER than this"   -> start at -infinity
        // upper = "everything must be SMALLER than this"  -> start at +infinity
        return helper(root, INT_MIN, INT_MAX);
    }

private:
    bool helper(TreeNode* root, int low, int upper){

        // Empty tree = nothing to break = valid.
        if(root == nullptr) return true;

        // THE CHECK:
        // root->val must be strictly BIGGER than low
        // AND strictly SMALLER than upper.
        // If it breaks either rule, whole tree is invalid.
        if(root->val >= upper || root->val <= low) return false;

        // Going LEFT  -> values must be SMALLER than root->val from now on
        //             -> so "upper" tightens to root->val
        //             -> "low" stays whatever it already was
        //
        // Going RIGHT -> values must be BIGGER than root->val from now on
        //             -> so "low" tightens to root->val
        //             -> "upper" stays whatever it already was
        return helper(root->left, low, root->val) &&
               helper(root->right, root->val, upper);
    }
};

// ============================================================
// STEP BY STEP TRACE on the example tree above:
//
// helper(2, low=-inf, upper=+inf)
//   check: -inf < 2 < +inf   -> OK
//   go left:  helper(1, low=-inf, upper=2)      // upper became 2
//   go right: helper(3, low=2,    upper=+inf)   // low became 2
//
// helper(1, low=-inf, upper=2)     [this is 2's left child]
//   check: -inf < 1 < 2   -> OK
//   no children -> return true
//
// helper(3, low=2, upper=+inf)     [this is 2's right child]
//   check: 2 < 3 < +inf   -> OK
//   go left:  helper(1, low=2, upper=3)   // low STAYS 2 (carried down from root!)
//   go right: helper(5, low=3, upper=+inf)
//
// helper(1, low=2, upper=3)        [this is 3's left child, the tricky one]
//   check: is 1 > low(2)?  NO, 1 <= 2   -> FAILS
//   return false
//
// Because this one call returns false, the "&&" chain collapses
// all the way back up, so isValidBST(2) = false. Correct!
//
// KEY TAKEAWAY: the "low=2" didn't come from node 3 (1's direct parent).
// It came from all the way back at the root, and got carried down
// through every recursive call. That's how a deep node still
// "remembers" the rules set by its grandparent, great-grandparent, etc.
// ============================================================