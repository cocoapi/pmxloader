#include <fstream>
#include "Pmx.h"

pmx::PMX_DEFORM::PMX_DEFORM(const char& type) : weight1(1.0f) {
	switch (type) {
	case 1:
		index1 = new char;
		break;
	case 2:
		index1 = new short;
		break;
	case 4:
		index1 = new int;
		break;
	default:
		index1 = NULL;
	}
}

pmx::PMX_DEFORM2::PMX_DEFORM2(const char& type) : PMX_DEFORM(type) {
	switch (type) {
	case 1:
		index2 = new char;
		break;
	case 2:
		index2 = new short;
		break;
	case 4:
		index2 = new int;
		break;
	default:
		index2 = NULL;
	}
}

pmx::PMX_DEFORM4::PMX_DEFORM4(const char& type) : PMX_DEFORM2(type) {
	switch (type) {
	case 1:
		index3 = new char;
		index4 = new char;
		break;
	case 2:
		index3 = new short;
		index4 = new short;
		break;
	case 4:
		index3 = new int;
		index4 = new int;
		break;
	default:
		index3 = NULL;
		index4 = NULL;
	}
}

pmx::PMX_VERTEX::PMX_VERTEX(const char& app, const char& defo, const char& type) :
	postion(),
	textureU(0.0f),
	textureV(0.0f),
	Edge(0.0f) 
{
	Appendix = new fVector::vec4[app];
	switch (defo) {
	case 0:
		Defrom = new pmx::PMX_DEFORM(type);
		break;
	case 1:
		Defrom = new pmx::PMX_DEFORM2(type);
		break;
	case 2:
		Defrom = new pmx::PMX_DEFORM4(type);
		break;
	case 4:
		Defrom = new pmx::PMX_SDEFORM(type);
		break;
	default:
		Defrom = NULL;
	}
}

//load model and data from file
bool pmx::PMX_MODEL::readModel(const char* path) {
	std::ifstream model(path, std::ifstream::binary);
	if (!model) {
		return false;
	}
	else {
		//check signature
		char buffer[4];
		model.read(buffer, 4);
		if (buffer[0] == 'P' &&
			buffer[1] == 'M' &&
			buffer[2] == 'X' &&
			buffer[3] == ' ') {
			model.read(buffer, 4);
			this->version = (float&)buffer;
			model.read(buffer, 1);
			model.read(buffer, 4);
			this->textEncoding = buffer[0];
			this->appendixUV = buffer[1];
			this->vertexIndexSize = buffer[2];
			this->textureIndexSize = buffer[3];
			model.read(buffer, 4);
			this->materialIndexSize = buffer[0];
			this->boneIndexSize = buffer[1];
			this->morphIndexSize = buffer[2];
			this->rigidbodyIndexSize = buffer[3];
			int length;
			model.read(buffer, 4);
			length = (int&)buffer;
			for (int i = 0; i < length/2; i++) {
				model.read(buffer, 2);
				this->modelName += (wchar_t&)buffer;
			}
			model.read(buffer, 4);
			length = (int&)buffer;
			for (int i = 0; i < length / 2; i++) {
				model.read(buffer, 2);
				this->englishName += (wchar_t&)buffer;
			}
			model.read(buffer, 4);
			length = (int&)buffer;
			for (int i = 0; i < length / 2; i++) {
				model.read(buffer, 2);
				this->modelComment += (wchar_t&)buffer;
			}
			model.read(buffer, 4);
			length = (int&)buffer;
			for (int i = 0; i < length / 2; i++) {
				model.read(buffer, 2);
				this->englishComment += (wchar_t&)buffer;
			}
			model.read(buffer, 4);
			this->vertexCount = (int&)buffer;
			for (int i = 0; i < vertexCount; i++) {

			}
			return true;
		}
		return false;
	}
}