#include"PQueue.h"

int calculatePriority(const SinhVien* x) {
	int priority = 0;

	priority += (x->IsCntt ? 0 : 100000);

	priority += x->SoKhoa * 10000;

	priority += (x->IsGoodHeal ? 1000 : 0);

	priority += x->CV * 100;

	priority += x->Tgian;

	return priority;
}