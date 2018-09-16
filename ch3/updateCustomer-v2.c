void readCustomer(FILE *cFile, Customer *cRec) {
	fread(cRec, sizeof(*cRec), 1, cFile);
}

void writeCustomer(FILE *cFile, Customer *cRec) {
	rewind(cFile);
	fwrite(cRec, sizeof(*cRec), 1, cFile);
}

void updateCustomer(const char *fName, double newBalance) {
	FILE *cFile;
	Customer cRec;
	cFile = fopen(fName, "r+"); // >---
	readCustomer(cFile, &cRec); // /
	if (newBalance >= 0.0) { // /
		cRec.balance = newBalance; // /
		writeCustomer(cFile, &cRec); // /
	} // /
	fclose(cFile); // <---
}