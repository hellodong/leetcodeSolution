

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double findeMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int *numsAll = NULL;
    int numsAllSize, index = 0, i = 0, m = 0;
    double medianValue = 0.0;

    numsAllSize = (nums1Size + nums2Size) / 2 + 1;
    numsAll = (int *)malloc(sizeof(int) * numsAllSize);
    if (NULL == numsAll)
    {
        printf ("Alloc Memery Error\r\n");

        return 0.0;
    }

    while(i < nums1Size && m < nums2Size)
    {
        if (i < nums1Size)
        {
            numsAll[index] = nums1[i];
            i++;
        }
        else if ( m < nums2Size)
        {
            numsAll[index] = nums2[m];
            m++;
        }
        

        if (++index == numsAllSize)
        {
            break;
        }
    }


        while(i < nums1Size && index < numsAllSize)
        {
            numsAll[index] = nums1[i];
            i++;
            index++;
        }
        while(m < nums2Size && index < numsAllSize)
        {
            numsAll[index] = nums2[m];
            m++;
            index++;
        }
 

    if ((nums1Size + nums2Size) % 2 == 1)
    {
        medianValue = numsAll[numsAllSize - 1];
    }
    else
    {
        medianValue = (numsAll[numsAllSize - 1] * 1.0 + numsAll[numsAllSize - 2] * 1.0) / 2.0;
    }
	free(numsAll);
	
    return medianValue;

}


int main (void)
{
    int nums1[] = {1,2};
    int nums2[] = {3,5};
    int nums1Size, nums2Size;
    double medianValue = 0.0;

    nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    medianValue = findeMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf ("Median Value :%f\r\n", medianValue);

    getchar();
    return 0;
}
