void readCustomer(const char *fName, Customer *cRec) {
	cFile = fopen(fName, " r+ ");
	fread(cRec, sizeof(*cRec), 1, cFile);
}

void writeCustomer(Customer *cRec) {
	rewind(cFile);
	fwrite (cRec, sizeof(*cRec), 1, cFile);
	fclose(cFile);
}

void updateCustomer(const char *fName, double newBalance) {
	Customer cRec;
	readCustomer(fName, &cRec);
	cRec.balance = newBalance;
	writeCustomer(&cRec);
}
