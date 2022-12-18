#include <vector>
#include <unordered_map>

using namespace std;

// ����һ����ϣ��/Set
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

// ��������ԭ�ؽ��������̡�
// ����һ���ȽϺ���ⷽ��2��ʽ
// ���ԭ�ؽ��������൱�ڷ��乤����ÿ����������һ��������λ��ÿ����λ����רҵ�Կڣ���0��������0
// Ԫ�ز����ϸڡ������ǵ�Ŀ�ľ����ҳ�������˲ţ���0������λ�ж��0Ԫ�ؾ�����
// �����ȴ�0������λ��ʼ���������ȿ�0�����ǲ����Ѿ�רҵ�Կ��ˣ�����Ѿ�רҵ�Կڼ�nums[0]=0��
// �����Ǿ�����0��λ��1��λ�����0����û��רҵ�Կڣ���ô���ǿ�����0�����ϵ��˲ŵ���������Ӧ�ĸ�
// λ�ϣ�����num[0]=2�������ǾͰ�2���Ԫ��Ų������Ӧ�ĸ�λ�ϼ�num[2]�����ʱ�����������:
// 1��num[2]��λ���Ѿ���רҵ�Կڵ��˲��ˣ���num[2]=2�����˵���ո��Ǹ���num[0]�ϵ�2�������
// �˲ţ�����ֱ�ӽ��䷵�ؼ��ɡ�
// 2��num[2]�ϵĲ���רҵ�Կڵ��˲ţ������ǽ�num[0]�ϵ�Ԫ�غ�num[2]�ϵ�Ԫ�ؽ���������num[2]
// ���ҵ�רҵ�Կڵ��˲��ˡ�֮���ظ��������ֱ����num[0]�ҵ�רҵ�Կڵ��˲ţ�Ȼ���Դ�����
// ��num[1]���˲š���num[2]���˲ţ�ֱ���ҵ�������˲š�
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