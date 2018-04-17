#pragma once
#include <string>

namespace fVector {
	//2-float vector
	class vec2 {
	protected:
		float x;
		float y;

	public:
		vec2() : x(0.0f), y(0.0f) {};
		vec2(const float& newX, const float& newY) : x(newX), y(newY) {};
		vec2& operator+(vec2& oper) {
			vec2* result = new vec2;
			result->set(x + oper.x, y + oper.y);
			return *result;
		}
		vec2& operator-(vec2& oper) {
			vec2* result = new vec2;
			result->set(x - oper.x, y - oper.y);
			return *result;
		}
		virtual void operator+=(vec2& oper) {
			set(x + oper.x, y + oper.y);
		}
		virtual void operator-=(vec2& oper) {
			set(x - oper.x, y - oper.y);
		}

		virtual void set(const float& newX, const float& newY) {
			x = newX;
			y = newY;
		}
		void setX(const float& newX) { x = newX; };
		void setY(const float& newY) { y = newY; };
		float getX() { return x; };
		float getY() { return y; };
	};

	//3-float vector
	class vec3 : public vec2 {
	protected:
		float z;

	public:
		vec3() : vec2(), z(0.0f) {};
		vec3(const float& newX, const float& newY, const float& newZ) : vec2(newX, newY), z(newZ) {}
		vec3& operator+(vec2& oper) {
			vec3* result = new vec3;
			result->set(x + oper.getX(), y + oper.getY(), z);
			return *result;
		}
		vec3& operator-(vec2& oper) {
			vec3* result = new vec3;
			result->set(x - oper.getX(), y - oper.getY(), z);
			return *result;
		}
		vec3& operator+(vec3& oper) {
			vec3* result = new vec3;
			result->set(x + oper.x, y + oper.y, z + oper.z);
			return *result;
		}
		vec3& operator-(vec3& oper) {
			vec3* result = new vec3;
			result->set(x - oper.x, y - oper.y, z - oper.z);
			return *result;
		}

		virtual void operator+=(vec2& oper) {
			set(x + oper.getX(), y + oper.getY(), z);
		}
		virtual void operator-=(vec2& oper) {
			set(x - oper.getX(), y + oper.getY(), z);
		}
		virtual void operator+=(vec3& oper) {
			set(x + oper.x, y + oper.y, z + oper.z);
		}
		virtual void operator-=(vec3& oper) {
			set(x - oper.x, y - oper.y, z - oper.z);
		}

		virtual void set(const float& newX, const float& newY, const float& newZ){
			x = newX;
			y = newY;
			z = newZ;
		}
		void setZ(const float& newZ) { z = newZ; }
		float getZ() { return z; };
	};

	//4-float vector
	class vec4 : public vec3 {
	private:
		float w;
		
	public:
		vec4() : vec3(), w(0.0f) {};
		vec4(const float& newX, const float& newY, const float& newZ, const float& newW) : vec3(newX, newY, newZ), w(newW) {};
		vec4& operator+(vec4& oper) {
			vec4* result = new vec4;
			result->set(x + oper.x, y + oper.y, z + oper.z, w - oper.w);
			return *result;
		}
		vec4& operator-(vec4& oper) {
			vec4* result = new vec4;
			result->set((x - oper.x), y - oper.y, z - oper.z, w - oper.w);
			return *result;
		}

		void operator+=(vec2& oper) {
			set(x + oper.getX(), y + oper.getY(), z, w);
		}
		void operator-=(vec2& oper) {
			set(x - oper.getX(), y + oper.getY(), z, w);
		}
		void operator+=(vec3& oper) {
			set(x + oper.getX(), y + oper.getY(), z + oper.getZ(), w);
		}
		void operator-=(vec3& oper) {
			set(x - oper.getX(), y - oper.getY(), z - oper.getZ(), w);
		}
		void operator+=(vec4& oper) {
			set(x + oper.x, y + oper.y, z + oper.z, w + oper.w);
		}
		void operator-=(vec4& oper) {
			set(x - oper.x, y - oper.y, z - oper.z, w - oper.w);
		}

		void set(const float& newX, const float& newY, const float& newZ, const float& newW) {
			x = newX;
			y = newY;
			z = newZ;
			w = newW;
		}
		void setW(const float& newW) { w = newW; }
		float getW() { return w; };
	};
}

namespace pmx {
	class PMX_DEFORM {
	protected:
		void* index1;
		float weight1;

	public:
		PMX_DEFORM() : weight1(1.0f) {
			index1 = NULL;
		}
		PMX_DEFORM(const char&);

		~PMX_DEFORM() {
			if (index1) delete index1;
		}
		void setI1value(const char& nVal) { index1 = (void*)nVal; }
		void setI1value(const short& nVal) { index1 = (void*)nVal; }
		void setI1value(const int& nVal) { index1 = (void*)nVal; }
	};

	class PMX_DEFORM2 : public PMX_DEFORM {
	protected:
		void* index2;
		float weight2;

	public:
		PMX_DEFORM2() : PMX_DEFORM(), weight2(0.0f) {
			index2 = NULL;
		}
		PMX_DEFORM2(const char&);

		~PMX_DEFORM2() {
			if (index2) delete index2;
		}

		virtual void setWeight1(const float& newWeight) {
			weight1 = newWeight;
			weight2 = 1.0f - newWeight;
		}
		void setI2value(const char& nVal) { index2 = (void*)nVal; }
		void setI2value(const short& nVal) { index2 = (void*)nVal; }
		void setI2value(const int& nVal) { index2 = (void*)nVal; }
	};

	class PMX_DEFORM4 : public PMX_DEFORM2 {
	private:
		void* index3;
		void* index4;
		float weight3;
		float weight4;
	public:
		PMX_DEFORM4() : PMX_DEFORM2(), weight3(0.0f), weight4(0.0f) {
			index3 = NULL;
			index4 = NULL;
		}
		PMX_DEFORM4(const char&);
		~PMX_DEFORM4() {
			if (index3) delete index3;
			if (index4) delete index4;
		}

		void setWeight1(const float& newWeight) { weight1 = newWeight; };
		void setWeight2(const float& newWeight) { weight2 = newWeight; };
		void setWeight3(const float& newWeight) { weight3 = newWeight; };
		void setWeight4(const float& newWeight) { weight4 = newWeight; };
		void setI3value(const char& nVal) { index3 = (void*)nVal; }
		void setI3value(const short& nVal) { index3 = (void*)nVal; }
		void setI3value(const int& nVal) { index3 = (void*)nVal; }
		void setI4value(const char& nVal) { index4 = (void*)nVal; }
		void setI4value(const short& nVal) { index4 = (void*)nVal; }
		void setI4value(const int& nVal) { index4 = (void*)nVal; }
		void setWeights(const float& newWeight1, const float& newWeight2, const float& newWeight3, const float& newWeight4) {
			weight1 = newWeight1;
			weight2 = newWeight2;
			weight3 = newWeight3;
			weight4 = newWeight4;
		}
	};

	class PMX_SDEFORM : public PMX_DEFORM2 {
	private:
		fVector::vec3 C;
		fVector::vec3 R0;
		fVector::vec3 R1;
	public:
		PMX_SDEFORM() : PMX_DEFORM2(),
			C(),
			R0(),
			R1()
		{};
		PMX_SDEFORM(const char& type) : PMX_DEFORM2(type),
			C(),
			R0(),
			R1()
		{};

		void setC(const fVector::vec3& newC) { C = newC; };
		void setR0(const fVector::vec3& newR) { R0 = newR; };
		void setR1(const fVector::vec3& newR) { R1 = newR; };
	};

	class PMX_VERTEX {
	private:
		fVector::vec3 postion;
		float textureU;
		float textureV;
		fVector::vec4 *Appendix;
		PMX_DEFORM* Defrom;
		float Edge;
	public:
		PMX_VERTEX() :
			postion(),
			textureU(0.0f),
			textureV(0.0f),
			Edge(0.0f)
		{
			Appendix = NULL;
			Defrom = NULL;
		};
		PMX_VERTEX(const char&, const char&, const char& type);
		~PMX_VERTEX() {
			if (Appendix) delete Appendix;
			if (Defrom) delete Defrom;
		}
		void setPostion(const fVector::vec3& pos) {
			this->postion = pos;
		}
		void setPostion(const float& x, const float& y, const float& z) {
			this->postion.set(x, y, z);
		}
		void setDefrom(const char&, const char&);
		void setUV(const float& U, const float& V) {
			textureU = U;
			textureV = V;
		}
		void setEdge(const float& nEdge) {
			Edge = nEdge;
		}
	};

	class PMX_MODEL {
	private:
		float version;				// byte: 4 type: float	Note: 2.0
		char gCount;				//fixed at 8 for v2.0
		char textEncoding;			//0 or 1				Note: 0 is UTF-16LE, 1 is UTF-8
		char appendixUV;			//appendixUV counts		Note: 0~4
		char vertexIndexSize;		//vertex index size		Note: 1, 2, 4
		char textureIndexSize;		//texture index size	Note: 1, 2, 4
		char materialIndexSize;		//Material index size	Note: 1, 2, 4
		char boneIndexSize;			//Bone index size		Note: 1, 2, 4
		char morphIndexSize;		//Morph index size		Note: 1, 2, 4
		char rigidbodyIndexSize;	//Rigidbody index size	Note: 1, 2, 4
		std::wstring modelName;
		std::wstring modelComment;
		std::wstring englishName;
		std::wstring englishComment;
		int vertexCount;
		PMX_VERTEX* vertex;
	public :
		PMX_MODEL() :
			version(0.0f),
			gCount(8),
			textEncoding(0),
			appendixUV(0),
			vertexIndexSize(0),
			textureIndexSize(0),
			materialIndexSize(0),
			boneIndexSize(0),
			morphIndexSize(0),
			rigidbodyIndexSize(0),
			modelName((wchar_t*)""),
			englishName((wchar_t*)""),
			vertexCount(0)
		{};
		bool readModel(const char*);
	};
}

/*
# PMX 2.0 file format #

This is a description of the PMX file format. This is used for 3D models in Miku Miku Dance (MMD).

Since I couldn't find any English descriptions of the PMX file format, I've made this, which is translated from http://gulshan-i-raz.geo.jp/labs/2012/10/17/pmx-format1/. I haven't used this file format yet, so please don't ask me what everything means.
An English guide to the PMD file format, which preceeded PMX, can be found here: http://mikumikudance.wikia.com/wiki/MMD:Polygon_Model_Data.

If you want to learn more, there are some open source projects on GitHub which can read this format, so go take a look at them.

Note: fields with type text begins with an int (32 bit) with how many bytes of text the section is.
The encoding of the text is either UTF-8 or UTF-16, as specified by the Text Encoding byte in the header.

Field                   | bytes | type        | Notes
------------------------+-------+-----------+--------------------------------------------
-- Header --		    |       |           |
Text Encoding           | 1     | char      | 0 = UTF-16, 1 = UTF-8
Appendix UV             | 1     | char      | 0-4
Index Size				| 1     | char      | 1 = byte, 2 = short, 4 = int
--  Model info --		|       |           |
Character Name          | x     | text      |
English Character Name  | x     | text      |
Comment                 | x     | text      |
English Comment         | x     | text      |
-- Vertex Data --		|       |           |
Vertex Count            | 4     | int       |
Each Vertex:            |       |           |
- XYZ Position          | 4 * 3 | float     |
- UV Texture Coordinate | 4 * 2 | float     |
- Appendix UV (XYZW)    | 4 * x | float     | Number of elements specified in the Appendix UV header field.
- Weight Type           | 1     | char      | 0 = BDEF1, 1 = BDEF2, 2 = BDEF4, 4 = SDEF.
- If BDEF1 Weight Type: |       |           |
- - Bone 1 Index        | x     | x         | Type specified in the Bone Index Size header field. Bone weight is 1.0.
- If BDEF2 Weight Type: |       |           |
- - Bone 1 Index        | x     | x         | Type specified in the Bone Index Size header field.
- - Bone 2 Index        | x     | x         | Type specified in the Bone Index Size header field.
- - Weight 1            | 4     | float     | Weight 2 = 1.0 - Weight 1
- If BDEF4 Weight Type: |       |           |
- - Bone 1 Index        | x     | x         | Type specified in the Bone Index Size header field.
- - Bone 2 Index        | x     | x         | Type specified in the Bone Index Size header field.
- - Bone 3 Index        | x     | x         | Type specified in the Bone Index Size header field.
- - Bone 4 Index        | x     | x         | Type specified in the Bone Index Size header field.
- - Weight 1            | 4     | float     |
- - Weight 2            | 4     | float     |
- - Weight 3            | 4     | float     |
- - Weight 4            | 4     | float     |
- If SDEF Weight Type:  |       |           |
- - Bone 1 Index        | x     | x         | Type specified in the Bone Index Size header field.
- - Bone 2 Index        | x     | x         | Type specified in the Bone Index Size header field.
- - Weight 1            | 4     | float     | Weight 2 = 1.0 - Weight 1
- - C (XYZ)             | 4 * 3 | float     |
- - R0 (XYZ)            | 4 * 3 | float     |
- - R1 (XYZ)            | 4 * 3 | float     |
- Edge Scale            | 4     | float     |
-- Face Data --     |       |           |
Face Count              | 4     | int       |
Each Face:              |       |           |
- Vertex Index          | x     | x         | Type specified in Vertex Index Size header field.
-- Texture Data --    |       |           |
Texture Count           | 4     | int       |
Each Texture:           |       |           |
- File Name             | x     | text      |
-- Material Data --   |       |           |
Material Count          | 4     | int       |
Each Material:          |       |           |
- Name                  | x     | text      |
- English Name          | x     | text      |
- Diffuse Color (RGBA)  | 4 * 4 | float     |
- Specular Color (RGB)  | 4 * 3 | float     |
- Specularity           | 4     | float     |
- Ambient Color (RGB)   | 4 * 3 | float     |
- Drawing Mode Flag     | 1     | char      | 0x01 = Double-Sided
|           | 0x02 = Shadow
|           | 0x04 = Self shadow map
|           | 0x08 = Self shadow
|           | 0x10 = Draw edges
- Edge Color (RGB)      | 4 * 3 | float     |
- Edge Size             | 4     | float     |
- Texture Index         | x     | x         | Type specified in the Texture Index Size header field.
- Sphere Index          | x     | x         | Type specified in the Texture Index Size header field.
- Sphere Mode           | 1     | char      |
- Toon Flag             | 1     | char      |
- Toon Index            | x     | x         | If Toon Flag is 0, then it has the type specified in the Texture Index Size header field.
|       |           | If Toon Flag is 1, the size is 1 byte with a value from 0-9.
- Memo                  | x     | text      |
- From Face Number      | 4     | int       |

*/