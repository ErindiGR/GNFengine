
def print_files(name, file_list):
	print(name+'=\n[')
	for file in file_list:
		print(file)
	print(']')


env = Environment(
	CXXFLAGS = '-Ox /EHsc',
	LINKFLAGS = '/SUBSYSTEM:CONSOLE',
	CPPPATH = 'third_party/includes/',
	LIBPATH='third_party/libs/',
	TARGET_ARCH='x86')

env.VariantDir('bin/', 'src/')


file_names = [
	'main.cpp',
	'window.cpp',
	'world.cpp',
	'input.cpp',
	'entity.cpp',
	'renderer.cpp',
	'gui.cpp',
	'mesh.cpp',
	'box.cpp',
	'shader.cpp',
	'camera.cpp',
	'time.cpp',
	'texture.cpp',
	'transform.cpp',
	'system.cpp'
]

libs_name =[
	'user32.lib',
	'freetype/freetype.lib',
	'sdl/SDL2.lib',
	'sdl/SDL2main.lib',
	'glew/glew32.lib',
	'opengl32.lib',
]



src_file_names = ["bin/"+f for f in file_names]


print('==================================')
print_files('sources', src_file_names)
print_files('libs', libs_name)
print('==================================')


env.Program('build/game', src_file_names,LIBS=libs_name)