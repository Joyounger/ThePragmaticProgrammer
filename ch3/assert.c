

int main(int argc, char const *argv[])
{
	// 用断言检测排序算法是否正确
	for (int i = 0; i < num_entries - 1; ++i)
	{
		assert(sorted[i] <= sorted[i+1]);
	}

	return 0;
}