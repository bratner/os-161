void bratresetjump(){
	unsigned int i=0x800273f0; /* reset address */
	__asm volatile(
		".set volatile;"
		"jr %0;"
		: "=r" (i)
	);
};
