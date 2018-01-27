/*
# ================================================================================
#  LeetCode - Algorithms - 4. Median of Two Sorted Arrays
#  https://leetcode.com/problems/median-of-two-sorted-arrays/description/
# 
#  Language: Go
#  Author: ConradG
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
#   时间复杂度O(lg(m+n))的要求明显地暗示了要使用二分查找。
#   基本思路为分别对两个有序数组nums1, nums2作一个划分:
#
#   设 L1 = [nums1(1), nums1(2), ... , nums1(i)]
#      R1 = [nums1(i+1), ... ,nums1(nums1.length)]
#      (0 <= i <= nums1.length)
#   
#      L2 = [nums2(1), nums2(2), ... , nums2(j)]
#      R2 = [nums2(j+1), ... ,nums2(nums2.length)]
#      (0 <= j <= nums2.length)
#
#   且 i + j = (nums1.length + nums2.length + 1) / 2 (即总个数为奇数时L1或L2取到中位数)
#   设 L1 和 L2 的最大值为 a, R1 和 R2 的最大值为 b
#   则当且仅当 a <= b 时有：
#      1) 中位数为 a            (总元素个数为奇数)
#      2) 中位数为 (a + b) / 2  (总元素个数为偶数)
#  
#   对于不符合条件的划分，总是向a可能减小的方向进行二分查找。
#  
#
#   因为i和j可以取到边界值，所以第一次编码时写成了典型的if地狱 XD。 (代码附后)
#   仍然请教下使用Go的小伙伴有哪些可以改进的部分。
#
# * Go中不支持三元运算符 ? : (Whyyyyyyyy !)
# * Go中数组使用值传递
# ================================================================================
*/

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
 
    if len(nums1) < len(nums2) {
        return excute(&nums1, &nums2)
    } else {
        return excute(&nums2, &nums1)
    }
}

func excute(a *[]int, b *[]int) float64 {
    
    la, lb := len(*a), len(*b)
    if la == 0 {
        return float64((*b)[(lb - 1) / 2] + (*b)[lb / 2]) / 2.0
    }
    
    size := (la + lb + 1) / 2
    left, right := 0, la    // 因为前文保证了 la <= lb, 所以这里 i 可以取到[0, len(a)]
    
    var i, j int            // i, j 分别为L1, L2 的元素个数
    var min, max int        // min为L1和L2的最大值， max为R1和R2的最小值
    
    for{
        i = (left + right) / 2
        j = size - i
        
        //计算min
        if j == 0 || i != 0 && (*a)[i-1] > (*b)[j-1] {
            min = (*a)[i - 1]
            right = i - 1     //此时min取自L1, 那么当且仅当i减小时，min可能会变小
        } else {
            min = (*b)[j - 1]
            left = i + 1      //此时min取自L2, 那么当且仅当j减小(i增大)时，min可能会变小
        }
        
        //计算max
        if j == lb || i != la && (*a)[i] < (*b)[j] {
            max = (*a)[i]
        } else {
            max = (*b)[j]
        }
        
        //中止条件
        if min <= max {
            if (la + lb) % 2 == 1 {
                return float64(min)
            } else {
                return float64(min + max) / 2.0
            }   
        }
    }
}

/*
# 2080 / 2080 test cases passed.
# Status: Accepted
# Runtime: 39 ms
# Your runtime beats 58.21 % of golang submissions.
*/

/*
 * First Accepted
 * IF Hell
 *
 
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    
    l1, l2 := len(nums1), len(nums2)
    if l1 > l2 {
        return findMedianSortedArrays(nums2, nums1)
    }
    if l1 == 0 {
        return float64(nums2[(l2 - 1) / 2] + nums2[l2 / 2]) / 2.0
    }
    
    
    size := (l1 + l2 + 1) / 2
    left, right := 0, l1
    
    var i int
    var j int
    var k bool
    for{
        i = (left + right) / 2
        j = size - i
        
        if i == 0 {
            k = false
            if nums2[j - 1] <= nums1[0] {
                break;
            }
        } else if j == 0 {
            k = true
            if nums1[i - 1] <= nums2[0] {
                break;
            }
        } else {
            if nums1[i - 1] > nums2[j - 1] {
                k = true
                if(j == l2 || nums1[i - 1] <= nums2[j]){
                    break;
                }
            } else {
                k = false
                if(i == l1 || nums2[j - 1] <= nums1[i]){
                    break;
                }
            }
        }
        
        
        if k {
            right = i - 1
        } else {
            left = i + 1
        }
    }

    var min int
    var max int
    if k {
        min = nums1[i - 1]
    } else {
        min = nums2[j - 1]
    }
    
    if (l1 + l2) % 2 == 1 {
        return float64(min)
    }
    
    if i == l1 {
        max = nums2[j]
    } else if j == l2 {
        max = nums1[i]
    } else {
        if nums1[i] < nums2[j] {
            max = nums1[i]
        } else {
            max = nums2[j]
        }
    }
    
    return float64(min + max) / 2.0
}

*/
