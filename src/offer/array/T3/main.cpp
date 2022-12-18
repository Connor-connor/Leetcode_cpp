#include <vector>
#include <unordered_map>

using namespace std;

// 方法一：哈希表/Set
/*class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> map;
        for(int num : nums) {
            if(map[num]) return num;
            map[num] = true;
        }
        return -1;
    }
};*/

// 方法二：原地交换法【√】
// 想了一个比较好理解方法2方式
// 这个原地交换法就相当于分配工作，每个索引代表一个工作岗位，每个岗位必须专业对口，既0索引必须0
// 元素才能上岗。而我们的目的就是找出溢出的人才，既0索引岗位有多个0元素竞争。
// 我们先从0索引岗位开始遍历，首先看0索引是不是已经专业对口了，如果已经专业对口既nums[0]=0，
// 那我们就跳过0岗位看1岗位。如果0索引没有专业对口，那么我们看现在0索引上的人才调整到他对应的岗
// 位上，比如num[0]=2，那我们就把2这个元素挪到他对应的岗位上既num[2]，这个时候有两种情况:
// 1、num[2]岗位上已经有专业对口的人才了，既num[2]=2，这就说明刚刚那个在num[0]上的2是溢出的
// 人才，我们直接将其返回即可。
// 2、num[2]上的不是专业对口的人才，那我们将num[0]上的元素和num[2]上的元素交换，这样num[2]
// 就找到专业对口的人才了。之后重复这个过程直到帮num[0]找到专业对口的人才，然后以此类推
// 帮num[1]找人才、帮num[2]找人才，直到找到溢出的人才。
// https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/solution/mian-shi-ti-03-shu-zu-zhong-zhong-fu-de-shu-zi-yua/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == i) {
                i++;
                continue;
            }
            if(nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i],nums[nums[i]]);
        }
        return -1;
    }
};