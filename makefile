grafica31.py : onda.dat
	python grafica31.py
onda.dat: ecuacion31.x
	./ecuacion31.x 
	./ecuacion31.x > onda.dat
ecuacion31.x : ejercicio31.cpp
	c++ ejercicio31.cpp -o ecuacion31.x