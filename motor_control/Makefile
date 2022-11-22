main:
	gcc -D USE_DEV_LIB  -c  examples/main.c -o bin/main.o  -I ./lib -I ./lib/Config -I ./lib/MotorDriver -I ./lib/PCA9685
	gcc -D USE_DEV_LIB  -c  lib/Config/DEV_Config.c -o bin/DEV_Config.o 
	gcc -D USE_DEV_LIB  -c  lib/Config/dev_hardware_i2c.c -o bin/dev_hardware_i2c.o 
	gcc -D USE_DEV_LIB  -c  lib/Config/sysfs_gpio.c -o bin/sysfs_gpio.o 
	gcc -D USE_DEV_LIB  -c  lib/MotorDriver/motor_contr.c -o bin/motor_contr.o  -I ./lib/Config -I ./lib/PCA9685
	gcc -D USE_DEV_LIB  -c  lib/PCA9685/PCA9685.c -o bin/PCA9685.o  -I ./lib/Config
	gcc -D USE_DEV_LIB  ./bin/main.o ./bin/DEV_Config.o ./bin/dev_hardware_i2c.o ./bin/sysfs_gpio.o ./bin/motor_contr.o ./bin/PCA9685.o -o main  -lm

clean:
	rm *.o
