grafica31.py : oscilador.dat
	python grafica31.py
oscilador.dat: ecuacion31.x
	./ecuacion31.x 
	./ecuacion31.x > oscilador.dat
ecuacion31.x : ejercicio31.cpp
	c++ ejercicio31.cpp -o ecuacion31.x