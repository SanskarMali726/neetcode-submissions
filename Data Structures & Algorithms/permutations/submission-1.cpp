class Solution {
public:

    // Stores all the permutations we generate.
    vector<vector<int>> ans;


    /*
        BACKTRACKING FUNCTION

        nums  -> original array
        temp  -> current permutation that we are building
        used  -> tells whether an element of nums is already used

        Example:

        nums = [1,2,3]

        If:
        temp = [1,3]

        then:

        used = [true, false, true]

        Meaning:
        1 -> already used
        2 -> not used
        3 -> already used
    */
    void findCombination(vector<int>& nums,
                         vector<int>& temp,
                         vector<bool>& used) {


        /*
            BASE CASE

            If temp contains all elements of nums,
            we have created one complete permutation.

            Example:

            nums = [1,2,3]
            temp = [1,3,2]

            temp.size() == nums.size()

            Therefore [1,3,2] is a valid permutation.
        */
        if (temp.size() == nums.size()) {

            // Store the complete permutation.
            ans.push_back(temp);

            return;
        }


        /*
            TRY EVERY NUMBER

            This loop is very important.

            It tries every element of nums as the
            NEXT element of our permutation.

            j = 0 -> nums[0]
            j = 1 -> nums[1]
            j = 2 -> nums[2]

            This is also how 2 and 3 eventually get
            the FIRST position.

            We will understand this after the main logic.
        */
        for (int j = 0; j < nums.size(); j++) {


            /*
                If this element is already used in the
                current permutation, skip it.

                Example:

                nums = [1,2,3]
                temp = [1,3]

                used = [true,false,true]

                j = 0 -> 1 already used -> skip
                j = 1 -> 2 available -> use it
                j = 2 -> 3 already used -> skip
            */
            if (used[j])
                continue;


            /*
                CHOOSE

                We choose nums[j] as the next element
                of our current permutation.

                Mark it as used.
            */
            used[j] = true;

            // Add the chosen number to our permutation.
            temp.push_back(nums[j]);


            /*
                EXPLORE

                Now recursively choose the NEXT element.

                Example:

                temp = [1]

                Recursion will try to create:

                [1,2]
                [1,3]

                and eventually:

                [1,2,3]
                [1,3,2]
            */
            findCombination(nums, temp, used);


            /*
                BACKTRACK

                The recursive call has finished generating
                ALL permutations that start with nums[j].

                So now we undo our choice.

                Example:

                Suppose we had:

                temp = [1,2]

                After recursion finishes, we remove 2:

                temp = [1]

                This allows us to try 3 instead of 2.

                This is the most important part of
                BACKTRACKING:

                    CHOOSE
                       ↓
                    EXPLORE
                       ↓
                    UNDO
            */

            // Make this element available again.
            used[j] = false;

            // Remove it from the current permutation.
            temp.pop_back();
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {

        /*
            Initially, no element is used.

            nums = [1,2,3]

            used = [false,false,false]
        */
        vector<bool> used(nums.size(), false);

        // Initially our current permutation is empty.
        vector<int> temp;


        /*
            Start generating permutations.
        */
        findCombination(nums, temp, used);


        // Return all generated permutations.
        return ans;
    }
};