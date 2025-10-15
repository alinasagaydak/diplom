#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int len = 8;
    int sum = 0;
    std::vector<std::vector<int>> vec_6gamma = {};
    std::vector<std::vector<int>> vec_4gamma = {};
    std::vector<std::vector<int>> vec_2gamma = {};
    std::vector<std::vector<int>> vec_pairs = {};
    for (int i1 = 0; i1 < len; i1++) {
    	for (int i2 = i1+1; i2 < len; i2++) {
	    for (int i3 = i2+1; i3 < len; i3++) {
	    	for (int i4 = i3+1; i4 < len; i4++) { 
		    for (int i5 = i4+1; i5 < len; i5++) {
		    	for (int i6 = i5+1; i6 < len; i6++) {
			    std::cout << i1 << i2 << i3 << i4 << i5 << i6 << std::endl;
			    vec_6gamma.push_back({i1, i2, i3, i4, i5, i6});
			    sum++;
			}
		    }
		}
	    }
	}
    }

    std::cout << sum << std::endl;
    std::cout << std::endl;

    int sum1 = 0;
    for (int i1 = 0; i1 < 6; i1++) {
        for (int i2 = i1+1; i2 < 6; i2++) {
	    for (int i3 = i2+1; i3 < 6; i3++) {
	    	for (int i4 = i3+1; i4 < 6; i4++) {
		    sum1++;
		    std::vector<int> vec2 = {vec_6gamma[0][i1], vec_6gamma[0][i2], vec_6gamma[0][i3], vec_6gamma[0][i4]};
		    std::vector<int> diff;
		    std::set_difference(vec_6gamma[0].begin(), vec_6gamma[0].end(), vec2.begin(), vec2.end(),
                        std::inserter(diff, diff.begin()));
		    
		    vec_4gamma.push_back(vec2);
		    vec_2gamma.push_back(diff);
		    
		    std::cout << vec_6gamma[0][i1] << vec_6gamma[0][i2] << vec_6gamma[0][i3] << vec_6gamma[0][i4] << 
				"\t" << diff[0] << diff[1] << std::endl;
		}
	    }
	}
    }

    std::cout << sum1 << std::endl;
    std::cout << std::endl;

    int sum2 = 0;
    for (int i1 = 0; i1 < 4; i1++) {
    	for (int i2 = i1+1; i2 < 4; i2++) {
	    vec_pairs.push_back({vec_4gamma[0][i1], vec_4gamma[0][i2]});
	    std::cout << vec_4gamma[0][i1] << vec_4gamma[0][i2] << std::endl;
	    sum2++;
	}
    }
    std::cout << sum2 << std::endl;
    return 0;
}
