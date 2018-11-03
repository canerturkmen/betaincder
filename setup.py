import io
import os

try:
    from distutils.core import setup
    from distutils.extension import Extension
except ImportError:
    from setuptools import setup, Extension

from Cython.Build import cythonize

DESCRIPTION = "compute the incomplete Beta function and its derivatives"
CLASSIFIERS = [
    'Programming Language :: Python :: 2.7',
    'Programming Language :: Cython',
    'Development Status :: 2 - Pre-Alpha',
    'Intended Audience :: Developers',
    'Intended Audience :: Science/Research',
    'License :: OSI Approved :: MIT License',
    'Topic :: Scientific/Engineering',
    'Topic :: Scientific/Engineering :: Information Analysis',
    'Topic :: Scientific/Engineering :: Mathematics'
]

# make description
try:
    here = os.path.abspath(os.path.dirname(__file__))
    with io.open(os.path.join(here, 'README.markdown'), encoding='utf-8') as f:
        LONG_DESCRIPTION = '\n' + f.read()
except:
    LONG_DESCRIPTION = DESCRIPTION

# make extension
ext_betaincder = Extension("betaincder.c.betaincder", ["betaincder/c/betaincder.pyx"],
                               libraries=["m"], extra_compile_args=["-O3", "-march=native", "-std=c99"])

setup(name="betaincder",
      version="0.1",
      description=DESCRIPTION,
      long_description=LONG_DESCRIPTION,
      long_description_content_type="text/markdown",
      author="Caner Turkmen",
      author_email="caner.turkmen@boun.edu.tr",
      ext_modules=cythonize([ext_betaincder]),
      packages=["betaincder", "betaincder.c"],
      setup_requires=["Cython"],
      license="MIT",
      package_dir={'betaincder.c': 'betaincder/c/'},
      package_data={'betaincder.c': ['*.pxd', '*.h']}
)
