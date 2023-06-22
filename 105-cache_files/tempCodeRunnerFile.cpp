//escribo el objeto en el archivo
    // archivo.write(reinterpret_cast<const char *>(p), sizeof(perro));
    // archivo.write(reinterpret_cast<const char *>(p1), sizeof(perro));
    // // cierro el archivo
    // archivo.close();
    // // leo el archivo
    // ifstream archivo2("perros.dat", ios::binary);
    // // imprimo el objeto
    // perro *p2 = new perro("", 0, "");
    // archivo2.read(reinterpret_cast<char *>(p2), sizeof(perro));
    // p2->mostrar();
    // // reinicio el puntero del archivo
    // archivo2.seekg(0);
    // perro *p3 = new perro("", 0, "");
    // archivo2.read(reinterpret_cast<char *>(p3), sizeof(perro));
    // p3->mostrar();
    // p2->mostrar();
    // // correr el puntero del archivo 1 objeto
    // archivo2.seekg(sizeof(perro));
    // perro *p4 = new perro("", 0, "");
    // archivo2.read(reinterpret_cast<char *>(p4), sizeof(perro));
    // p4->mostrar();
    // archivo2.close();