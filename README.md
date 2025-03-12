# 📖 TerminalNote - Gestor de Notas en Terminal  
*Organiza tus ideas con eficiencia: Sistema de notas persistente con interfaz CLI intuitiva*

![Demo de la Aplicación](https://raw.githubusercontent.com/llromerorr/TerminalNote/refs/heads/master/resource/preview.gif)

## 🚀 Características Principales
- **Sistema de libros**: Organiza notas en diferentes categorías
- **Persistencia de datos**: Almacenamiento en archivos binarios
- **Interfaz colorida**: Soporte para formato de texto y colores ANSI
- **Multiplataforma**: Compatible con Windows y Linux
- **Comandos intuitivos**: Sintaxis estilo UNIX con autodocumentación
- **Gestión avanzada**:
  - Búsqueda y eliminación de notas
  - Estadísticas de uso
  - Sistema de advertencias para libros llenos

## 🧩 Estructura del Proyecto
```
src/
├── headers/
│   ├── app.h          // Lógica principal de la aplicación
│   ├── note.h         // Estructura y manipulación de notas
│   ├── database.h     // Sistema de almacenamiento persistente
│   ├── console.h      // Utilidades de interfaz de usuario
│   ├── date.h        // Manejo de fechas y tiempos
│   ├── terminalnote.h // Punto de integración de componentes
│   └── textformat.h  // Códigos ANSI para formato de texto
├── main.c             // Punto de entrada principal
└── (Sistema de build)
```

## 🛠️ Tecnologías Clave
- **Lenguaje**: C11 (Compatibilidad completa con estándares)
- **Bibliotecas**:
  - Standard I/O (gestión de archivos)
  - Time.h (manejo de fechas/horas)
  - String.h (manipulación de cadenas)
- **Paradigmas**:
  - Programación modular
  - Gestión manual de memoria
  - Interfaz conversacional (REPL)
- **Persistencia**:
  - Archivos binarios estructurados
  - Sistema de libros con metadata
  - Recuperación de datos ante fallos

## 🔧 Compilación y Ejecución
1. **Requisitos**:
   - Compilador C (GCC o Clang)
   - Sistema Linux/Windows (soporte nativo)

2. **Compilar proyecto**:
```bash
gcc main.c -o tnote -Wall -Wextra -pedantic
```

3. **Ejecutar**:
```bash
./tnote
```

## 🎮 Comandos Disponibles
```bash
# Operaciones básicas
note "Título : Contenido"  # Crear nueva nota
show [id|book]             # Mostrar notas
delete <id>                # Eliminar nota

# Gestión de libros
new <nombre_libro>         # Crear nuevo libro
open <libro>               # Cambiar libro activo
destroy                    # Eliminar libro actual

# Utilidades
clear                      # Limpiar pantalla
help                       # Mostrar ayuda
exit                       # Salir del programa
```

## 📌 Roadmap de Mejoras
- [ ] Sistema de búsqueda full-text
- [ ] Exportación a formato Markdown/PDF
- [ ] Soporte para etiquetas/categorías
- [ ] Modo portable (configuración en USB)
- [ ] Integración con editores externos

---

🧑💻 **Desarrollador Principal**:  
[@llromerorr](https://github.com/llromerorr) desde Venezuela 🇻🇪

📥 **Descarga última versión**:  
[Repositorio del Proyecto](https://github.com/tu_usuario/TerminalNote)

🔐 **Licencia**:  
MIT License - Libre para uso y modificación